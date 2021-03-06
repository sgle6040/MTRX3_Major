/**
 * @file PrimaryInterfaceOutput.c
 * @date October 2016
 * @brief Output to primary interface 
 * 
 * Writes messages to LCD based on current state of UI module.
 * Also output to LED's based on robot commander state and
 * servo motor (not implemented in final product).
 * 
 * @author Wilhelm Marais
 *
 * 
 */
#include "UserInterface.h"
#include <stdio.h>
#include <p18f4520.h>
//#include "servo.h"

#define INITIALISE          0
#define USER_MANUAL_MODE 	1
#define USER_AUTO_MODE 		2
#define	FACTORY_MODE		3

#define	PRIMARY_INTERFACE_MODE	0
#define	SECONDARY_INTERFACE_MODE	1

#define ENTRY               0
#define NORMAL              1
#define PARAMETER           2
#define	PID					3

#define BirdMoving      PORTCbits.RC0
#define BirdFound       PORTCbits.RC1
#define RobotMoving     PORTCbits.RC5
//#define PiezoControl    PORTCbits.RC3

void LEDSetup(void){
    PORTCbits.RC0=0;
    TRISCbits.RC0=0;
    PORTCbits.RC1=0;
    TRISCbits.RC1=0;
    PORTCbits.RC5=0;
    TRISCbits.RC5=0;
    
}
void  LEDOutput(int parrot_found,int parrot_moving,char instructionFlag){
    if(parrot_found){
       BirdFound=1;
    }else{
       BirdFound=0;
    }
    if(parrot_moving){
       BirdMoving=1;
    }else{
       BirdMoving=0;
    }
    if(instructionFlag){
       RobotMoving=1;
    }else{
       RobotMoving=0;
    }
}


/** 
 * A string array.
 * Used for storing parameter values for printing
 * using sprintf function.
 */
char string[16];

/** Outputs to primary interface. Based on current state
 * of the UI module, outputs to LED's and LCD.
 */
void    PrimaryInterfaceOutput(struct UserInterfaceOutput *UIOutput,int interface_mode,int state_variable,int menu_position){

    LEDOutput((UIOutput->parrot_found),(UIOutput->parrot_moving),(UIOutput->instructionFlag));
    //servoOutput(UIOutput->parrotDirection);

    if((UIOutput->State)==INITIALISE){
            //............................
        switch(state_variable){
            case ENTRY:
                //LCDClear();
                LCDLine1ROMWrite("Welcome to HSS  ");
                LCDLine2ROMWrite("Initialising... ");
                break;
            case NORMAL:
                //LCDClear();
                LCDLine1ROMWrite("Initialising... ");
                LCDLine2ROMWrite("                ");
                break;
        }
    }
    if(interface_mode==SECONDARY_INTERFACE_MODE){
        
        //////////////////////////////////////////////////////////////

        //////////////////////////////////////////////////////////////
        if((UIOutput->State)==USER_MANUAL_MODE){
            //............................
            if(state_variable==ENTRY){
                //LCDClear();
                LCDLine1ROMWrite("USER_MANUAL_MODE");
                LCDLine2ROMWrite("Please wait     ");
            }
            //...............................
            if(state_variable==NORMAL){
                switch(menu_position){
                    case 0:
                        //LCDClear();
                        LCDLine1ROMWrite("0-SET_MOTORS_ON ");
                        LCDLine2ROMWrite("                ");
                        break;
                    case 1:
                        //LCDClear();
                        LCDLine1ROMWrite("1-SET_MOTORS_OFF");
                        LCDLine2ROMWrite("                ");
                        break;
                    case 2:
                        //LCDClear();
                        LCDLine1ROMWrite("2-SET_SPEED_MAX ");
                        LCDLine2ROMWrite("                ");
                        break;
                    case 3:
                        //LCDClear();
                        LCDLine1ROMWrite("3-SET_USER_AUTO ");
                        LCDLine2ROMWrite("                ");
                        break;
                    case 4:
                        //LCDClear();
                        LCDLine1ROMWrite("4-SET_FACTORY   ");
                        LCDLine2ROMWrite("                ");
                        break;
                }

            }
            //..............................
            if(state_variable==PARAMETER){
                switch(menu_position){
                    case 0:
                        //LCDClear();
                        LCDLine1ROMWrite("MOTORS_ON");				/////////////////////////////////////////////////////////
                        LCDLine2ROMWrite("                ");
                        break;
                    case 1:
                        //LCDClear();
                        LCDLine1ROMWrite("MOTORS_OFF");			/////////////////////////////////////////////////////////
                        LCDLine2ROMWrite("                ");
                        break;
                    case 2:
                        //LCDClear();

                        sprintf(string,"%d               ",(UIOutput->max_robot_speed));
                        LCDLine1ROMWrite("MAX SPEED=      ");
                        LCDLine2RAMWrite(string);
                        break;
                    case 4:
                        //LCDClear();
                        LCDLine1ROMWrite("Enter Passcode: ");
                        LCDLine2ROMWrite("                ");
                        break;
                }
            }

        }

        ////////////////////////////////////////////////////////
        if((UIOutput->State)==USER_AUTO_MODE){
            //............................
            if(state_variable==ENTRY){
                //LCDClear();
                LCDLine1ROMWrite("USER_AUTO_MODE  ");
                LCDLine2ROMWrite("Please wait     ");
            }
            //...............................
            if(state_variable==NORMAL){
                switch(menu_position){
                    case 0:
                        //LCDClear();
                        LCDLine1ROMWrite("0-SET_FINDPARROT");
                        LCDLine2ROMWrite("                ");
                        break;
                    case 1:
                        //LCDClear();
                        LCDLine1ROMWrite("1-SET_USERMANUAL");
                        LCDLine2ROMWrite("                ");
                        break;
                }
            }

        }

        ////////////////////////////////////////////////////////
        if((UIOutput->State)==FACTORY_MODE){
            //............................
            if(state_variable==ENTRY){
                //LCDClear();
                LCDLine1ROMWrite("FACTORY_MODE    ");
                LCDLine2ROMWrite("Please wait     ");
            }
            //...............................
            if(state_variable==NORMAL){
                switch(menu_position){
                    case 0:
                        //LCDClear();
                        LCDLine1ROMWrite("0-SET_PID_GAINS ");
                        LCDLine2ROMWrite("Not implemented ");
                        break;
                    case 1:
                        //LCDClear();
                        LCDLine1ROMWrite("1-SET_SPEED_MAX ");
                        LCDLine2ROMWrite("                ");
                        break;
                    case 2:
                        //LCDClear();
                        LCDLine1ROMWrite("2-SET_YAW_RATE  ");
                        LCDLine2ROMWrite("                ");
                        break;
                    case 3:
                        //LCDClear();
                        LCDLine1ROMWrite("3-SET_IR_SAMPLES");
                        LCDLine2ROMWrite("                ");
                        break;
                    case 4:
                        //LCDClear();
                        LCDLine1ROMWrite("4-SET_IR_RATE   ");
                        LCDLine2ROMWrite("                ");
                        break;
                    case 5:
                        //LCDClear();
                        LCDLine1ROMWrite("5-SET_RF_SAMPLES");
                        LCDLine2ROMWrite("                ");
                        break;
                    case 6:
                        //LCDClear();
                        LCDLine1ROMWrite("6-SET_MODEMANUAL");
                        LCDLine2ROMWrite("                ");
                        break;
                }
            }
            //..............................
            if(state_variable==PARAMETER){
                switch(menu_position){
                    case 0:
                        break;
                    case 1:
                        //LCDClear();

                        sprintf(string,"%d               ",(UIOutput->max_robot_speed));
                        LCDLine1ROMWrite("MAX SPEED=      ");
                        LCDLine2RAMWrite(string);
                        break;
                    case 2:
                        //LCDClear();

                        sprintf(string,"%d               ",(UIOutput->max_yaw_rate));
                        LCDLine1ROMWrite("MAX YAW RATE=   ");
                        LCDLine2RAMWrite(string);
                        break;
                    case 3:
                        //LCDClear();

                        sprintf(string,"%d               ",(UIOutput->ir_samples));
                        LCDLine1ROMWrite("IR SAMPLES=     ");
                        LCDLine2RAMWrite(string);
                        break;
                    case 4:
                        //LDClear();

                        sprintf(string,"%d               ",(UIOutput->ir_rate));
                        LCDLine1ROMWrite("IR SAMPLE RATE= ");
                        LCDLine2RAMWrite(string);
                        break;
                    case 5:
                        //LCDClear();

                        sprintf(string,"%d               ",(UIOutput->rf_samples));
                        LCDLine1ROMWrite("RF SAMPLES=     ");
                        LCDLine2RAMWrite(string);
                        break;
                }
            }
            if(state_variable==PID){
            	switch(menu_position){
            		case 0:
                        //LCDClear();
                        sprintf(string,"P GAIN= %d       ",(UIOutput->p_gain));
                        LCDLine1RAMWrite(string);
                        LCDLine2ROMWrite("Not implemented ");
                        break;
            		case 1:
                        LCDClear();
                        sprintf(string,"I GAIN= %d       ",(UIOutput->i_gain));
                        LCDLine1RAMWrite(string);
                        LCDLine2ROMWrite("Not implemented ");
                        break;
            		case 2:
                        LCDClear();
                        sprintf(string,"D GAIN= %d       ",(UIOutput->d_gain));
                        LCDLine1RAMWrite(string);
                        LCDLine2ROMWrite("Not implemented ");
                        break;

            	}
            }
        }
    }
    else if(interface_mode==PRIMARY_INTERFACE_MODE){

        if((UIOutput->State)==USER_MANUAL_MODE){
            //............................
            switch(state_variable){
                case ENTRY:
                    //LCDClear();
                    LCDLine1ROMWrite("USER_MANUAL_MODE");
                    LCDLine2ROMWrite("Please wait     ");
                    break;
                case NORMAL:
                	if((UIOutput->full_scan)){
						//LCDClear();
						LCDLine1ROMWrite("Full Scan       ");
						LCDLine2ROMWrite("Scanning...     ");
					}else if((UIOutput->half_scan)){
						//LCDClear();
						LCDLine1ROMWrite("Half Scan       ");
						LCDLine2ROMWrite("Scanning...     ");
					}else{
                    //LCDClear();
                    sprintf(string,"L=%d cm R=%d cm ",(UIOutput->ir_left),(UIOutput->ir_right));
                    LCDLine1RAMWrite(string);
                    sprintf(string,"F=%d cm SS=%d     ",(UIOutput->ir_front),(UIOutput->parrotDistance));
                    LCDLine2RAMWrite(string);
					}
                    break;
            }
        }
        if((UIOutput->State)==USER_AUTO_MODE){
            //............................
            switch(state_variable){
                case ENTRY:
                    //LCDClear();
                    LCDLine1ROMWrite("USER_AUTO_MODE  ");
                    LCDLine2ROMWrite("Please wait     ");
                    break;
                case NORMAL:
                	if((UIOutput->full_scan)){
						//LCDClear();
						LCDLine1ROMWrite("Full Scan       ");
						LCDLine2ROMWrite("Scanning...     ");
					}else if((UIOutput->half_scan)){
						//LCDClear();
						LCDLine1ROMWrite("Half Scan       ");
						LCDLine2ROMWrite("Scanning...     ");
					}else{
                    //LCDClear();
                    LCDLine1ROMWrite("USER_AUTO_MODE  ");
                    LCDLine2ROMWrite("                ");
					}
                    break;
            }
        }
        if((UIOutput->State)==FACTORY_MODE){
            switch(state_variable){
                case ENTRY:
                    //LCDClear();
                    LCDLine1ROMWrite("FACTORY_MODE    ");
                    LCDLine2ROMWrite("Please wait     ");
                    break;
                case NORMAL:
                	if((UIOutput->full_scan)){
                		//LCDClear();
                		LCDLine1ROMWrite("Full Scan       ");
                		LCDLine2ROMWrite("Scanning...     ");
                	}else if((UIOutput->half_scan)){
                		//LCDClear();
                		LCDLine1ROMWrite("Half Scan       ");
                		LCDLine2ROMWrite("Scanning...     ");
                	}else{
                    //LCDClear();
                    sprintf(string,"L=%d cm R=%d cm ",(UIOutput->ir_left),(UIOutput->ir_right));
                    LCDLine1RAMWrite(string);
                    sprintf(string,"F=%d cm SS=%d     ",(UIOutput->ir_front),5);
                    LCDLine2RAMWrite(string);
                	}
                    break;
            }
        }
    }
}