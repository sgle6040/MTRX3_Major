#include "usart.h"
#include "p18f4520.h"
#include <stdio.h>
#include <stdlib.h>
#include "delays.h"
//#include "pconfig.h"
//#include "ConfigRegs_18F4520.h"


#define CR 0x0D
#define FULL 0xFF
#define chirpSound 'z'
#define BIT0 0x01
#define startChar 'K'
#define endChar 'O'
#define sep '*'
#define comma ','
#define endBuf 0xFF
#define valMask 0x0F
#define processing 0
#define sum 2

void getRSSI(char * buffer, char * signalStrength);
void sendMsg(char *tx);
char createCheckSum(char * string);
void intToPackage(int* data, char* dataInChar);
void RSSIToPackage(char* RSSIval, char* dataInPack);

/**
 * @brief Initiate the USART communications on the robot 
 * @usage allows the 2 RF modules to communicate to each other 
 */
void commsSetup(void) {
     //PORTC Bit 6 Is TX (PIN 25)
    TRISCbits.TRISC6 = 0;
    //PORTC Bit 7 Is RX (PIN 26)
    TRISCbits.TRISC7 = 1;
    //Short Pause
    Delay10KTCYx(250);
    //Configure USART - 9600 Baud
    OpenUSART( USART_TX_INT_OFF  &
             USART_RX_INT_ON  &
             USART_ASYNCH_MODE &
             USART_EIGHT_BIT   &
             USART_CONT_RX &
             USART_BRGH_HIGH, 64 );


    
}



/**
 * @brief send the data package from robot to commander 
 * @param values for IR in int form (Null terminated)
 * @param values for signal strength in char form (Null terminated)
 * @param the indication if the process is complete
 */
char startString[] = {FULL,startChar,FULL,NULL};
char endString[] = {endChar,FULL,NULL};
char separatorString[] = {sep,FULL,NULL};
char transmitData(int* IRVals,char* signalStrength,char processComplete) {
    char IRValsPackage[]; // data in mode that can be received
    char signalStrengthPackage[];
    //char checkSum;
    char checkPackage[] = {NULL,FULL,NULL}; // process complete and check sum 
    
    intToPackage(IRVals, IRValsPackage);
    RSSIToPackage(signalStrength, signalStrengthPackage);
    // create the security 
    //checkSum = createCheckSum(IRValsPackage) + createCheckSum(signalStrengthPackage) + processComplete;
    //checkPackage[processing] = processComplete; // insert check sum
    checkPackage[0] = processComplete;
    
    sendMsg(startString); // send the package that indicates the start
    sendMsg(IRValsPackage); // send IR
    sendMsg(separatorString); // separator 
    sendMsg(signalStrengthPackage); // send RSSI
    sendMsg(separatorString); // separator 
    sendMsg(checkPackage); // security
    sendMsg(endString); // send the package that indicates the end 
    
    return 0;
    
}

/*Called during receive interrupt to store data in buffer, sets flag high*/

/**
 * @brief interrupt routine for receive 
 * @usage when it detects the end bytes of the message ie the start and end
 * it toggles the flag which allows it to save
 * which means that it 1 instance of flag will cause it to save, the second will 
 * cause it to stop saving. The buffer ends with 0xFF
 */
char flag = 0x00; // for indication of save on/off
char* rcPtr;
char receiveData(char* buffer){
    //return 1;
        PIR1bits.RCIF=0; // clear receive flag
    
    if(RCREG == startChar){ // turn on save text flag
        flag = 1; // turn on 
        rcPtr = buffer; // point to beginning of buffer 
    }else if (RCREG == endChar){ // turn on save text flag
        flag = 0; // turn off
    }
    if(flag && RCREG != chirpSound){ // when flag is turned on discard all chirps
        rcPtr++; // save RCREG in circular buffer
        if(*rcPtr == endBuf){
            rcPtr = buffer;
        }
        *rcPtr = ReadUSART();
    }
    return 1;
}

/*Parses the receive buffer and modifies the instructions and instruction flag*/
char processReceived(char* buffer, int* instMag,char* instDir,char* commandFlag) {
    //remove RSSI receive flag
}


/**
 * @brief converts string of int values into string of char in package separated by comma
 * @param string of int data
 * @param string of char data thats been converted 
 */
void intToPackage(int* data, char* dataInChar){
    while(*data){
        *dataInChar = (*data) >> 8;
        dataInChar++; // increment buffer place 
        *dataInChar = FULL; // allow for falling edge resistor to detect
        dataInChar++; // increment buffer place 
        *dataInChar = (*data) & 0xFF;
        dataInChar++; // increment buffer place 
        *dataInChar = FULL; // allow for falling edge resistor to detect
        
        data++;
        *dataInChar = comma;
        dataInChar++; // increment buffer place 
        *dataInChar = FULL; // allow for falling edge resistor to detect
        dataInChar++;
    }  
    *dataInChar = NULL; // null terminated

}

/**
 * @brief converts string of char values into string in package
 * @param string of char ASCII data
 * @param string of char data thats been converted and separated 
 */
void RSSIToPackage(char* RSSIval, char* dataInPack){

    while(*RSSIval){
        *dataInPack = (*RSSIval)&valMask; // get rid of first byte 
        dataInPack++; // increment buffer place 
        *dataInPack = FULL; // allow for falling edge resistor to detect
        dataInPack++;
        RSSIval++;
    }   
    *dataInPack = NULL; // null terminated 

}

/**
 * @brief requests the value of RSSI
 * @usage it waits for the most recent chirp, then sends command get into command mode
 * sends ATDB request
 * ends command mode, the RSSI is saved by the receive ISR
 */
char ATCommandStart[] = "+++"; //Initialize AT Command Mode.
char ATCommandRSSI[] = "ATDB\r"; // read signal strength
char ATCommandEnd[] = "ATCN\r"; // end command

void getRSSI(char * buffer, char * signalStrength){
    
    while(RCREG != chirpSound); //wait till chirp received
    sendMsg(ATCommandStart); // start command mode
    while(RCREG != CR);
    sendMsg(ATCommandRSSI); // request RSSI
    while(RCREG != CR);
    sendMsg(ATCommandEnd); // end AT mode
    while(RCREG != CR);
    buffer ++; // originally pointing to the start byte
    while(*buffer != endChar){
        *signalStrength = *buffer;
        signalStrength++;
        buffer++;
    }
    *signalStrength = NULL; 

}

/**
 * @brief transmits string to other RF module on robot 
 * @param pointer to the string to be sent (NULL terminated)
 * @param pointer to the password representing type of instruction/response (NULL terminated)
 */
void sendMsg(char *tx){
    
    while (*tx) // send string
    {
        while (TXSTAbits.TRMT != 1); // wait till transmit buffer is empty
        putcUSART(*tx); // write  
        tx++;  
    } 

}
/**
 * @brief creates a check sum security measure 
 * @param string of values to be sent 
 * @return sum of individual values stored 
 */
// note , the max of the values is EF for sending to commander because first bit cannot be set
char createCheckSum(char * string){
    char checkSum = 0;
    while (*string) // while not end of string 
    {
        if(*string != FULL){ // when it is not the FF
            checkSum = checkSum + *string; 
        }      
    } 
    if (checkSum>0xEF){ // cap at EF 
        checkSum = 0xEF;
    }
    return checkSum;
}