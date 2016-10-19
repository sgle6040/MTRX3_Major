#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=cof
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Robot.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Robot.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=main.c user.c movement.c navigation.c communication.c stateControl.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/main.o ${OBJECTDIR}/user.o ${OBJECTDIR}/movement.o ${OBJECTDIR}/navigation.o ${OBJECTDIR}/communication.o ${OBJECTDIR}/stateControl.o
POSSIBLE_DEPFILES=${OBJECTDIR}/main.o.d ${OBJECTDIR}/user.o.d ${OBJECTDIR}/movement.o.d ${OBJECTDIR}/navigation.o.d ${OBJECTDIR}/communication.o.d ${OBJECTDIR}/stateControl.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/main.o ${OBJECTDIR}/user.o ${OBJECTDIR}/movement.o ${OBJECTDIR}/navigation.o ${OBJECTDIR}/communication.o ${OBJECTDIR}/stateControl.o

# Source Files
SOURCEFILES=main.c user.c movement.c navigation.c communication.c stateControl.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/Robot.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F452
MP_PROCESSOR_OPTION_LD=18f452
MP_LINKER_DEBUG_OPTION=  -u_DEBUGSTACK
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/main.o   main.c 
	@${DEP_GEN} -d ${OBJECTDIR}/main.o 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/user.o: user.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/user.o.d 
	@${RM} ${OBJECTDIR}/user.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/user.o   user.c 
	@${DEP_GEN} -d ${OBJECTDIR}/user.o 
	@${FIXDEPS} "${OBJECTDIR}/user.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/movement.o: movement.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/movement.o.d 
	@${RM} ${OBJECTDIR}/movement.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/movement.o   movement.c 
	@${DEP_GEN} -d ${OBJECTDIR}/movement.o 
	@${FIXDEPS} "${OBJECTDIR}/movement.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/navigation.o: navigation.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/navigation.o.d 
	@${RM} ${OBJECTDIR}/navigation.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/navigation.o   navigation.c 
	@${DEP_GEN} -d ${OBJECTDIR}/navigation.o 
	@${FIXDEPS} "${OBJECTDIR}/navigation.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/communication.o: communication.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/communication.o.d 
	@${RM} ${OBJECTDIR}/communication.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/communication.o   communication.c 
	@${DEP_GEN} -d ${OBJECTDIR}/communication.o 
	@${FIXDEPS} "${OBJECTDIR}/communication.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/stateControl.o: stateControl.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/stateControl.o.d 
	@${RM} ${OBJECTDIR}/stateControl.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/stateControl.o   stateControl.c 
	@${DEP_GEN} -d ${OBJECTDIR}/stateControl.o 
	@${FIXDEPS} "${OBJECTDIR}/stateControl.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
else
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/main.o   main.c 
	@${DEP_GEN} -d ${OBJECTDIR}/main.o 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/user.o: user.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/user.o.d 
	@${RM} ${OBJECTDIR}/user.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/user.o   user.c 
	@${DEP_GEN} -d ${OBJECTDIR}/user.o 
	@${FIXDEPS} "${OBJECTDIR}/user.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/movement.o: movement.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/movement.o.d 
	@${RM} ${OBJECTDIR}/movement.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/movement.o   movement.c 
	@${DEP_GEN} -d ${OBJECTDIR}/movement.o 
	@${FIXDEPS} "${OBJECTDIR}/movement.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/navigation.o: navigation.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/navigation.o.d 
	@${RM} ${OBJECTDIR}/navigation.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/navigation.o   navigation.c 
	@${DEP_GEN} -d ${OBJECTDIR}/navigation.o 
	@${FIXDEPS} "${OBJECTDIR}/navigation.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/communication.o: communication.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/communication.o.d 
	@${RM} ${OBJECTDIR}/communication.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/communication.o   communication.c 
	@${DEP_GEN} -d ${OBJECTDIR}/communication.o 
	@${FIXDEPS} "${OBJECTDIR}/communication.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/stateControl.o: stateControl.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/stateControl.o.d 
	@${RM} ${OBJECTDIR}/stateControl.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/stateControl.o   stateControl.c 
	@${DEP_GEN} -d ${OBJECTDIR}/stateControl.o 
	@${FIXDEPS} "${OBJECTDIR}/stateControl.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Robot.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE)   -p$(MP_PROCESSOR_OPTION_LD)  -w -x -u_DEBUG -m"${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"  -z__MPLAB_BUILD=1  -u_CRUNTIME -z__MPLAB_DEBUG=1 -z__MPLAB_DEBUGGER_SIMULATOR=1 $(MP_LINKER_DEBUG_OPTION) -l ${MP_CC_DIR}\\..\\lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/Robot.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
else
dist/${CND_CONF}/${IMAGE_TYPE}/Robot.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE)   -p$(MP_PROCESSOR_OPTION_LD)  -w  -m"${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"  -z__MPLAB_BUILD=1  -u_CRUNTIME -l ${MP_CC_DIR}\\..\\lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/Robot.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif