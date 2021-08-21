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
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/grbl_test1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/grbl_test1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=/home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/main.c /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/stepper.c /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/eeprom_in_ram.c /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/system_pic32.c /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/limits.c /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/settings.c /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/report.c /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/stepper_pic32.c /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/planner.c /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/eeprom_pic32.c /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/eeprom.c /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/probe.c /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/nuts_bolts_pic32.c /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/spindle_control_pic32.c /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/coolant_control.c /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/print.c /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/gcode.c /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/motion_control.c /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/protocol.c /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/serial.c /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/serial_pic32.c /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/spindle_control.c /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/system.c /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/nuts_bolts.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/203301211/main.o ${OBJECTDIR}/_ext/203301211/stepper.o ${OBJECTDIR}/_ext/203301211/eeprom_in_ram.o ${OBJECTDIR}/_ext/203301211/system_pic32.o ${OBJECTDIR}/_ext/203301211/limits.o ${OBJECTDIR}/_ext/203301211/settings.o ${OBJECTDIR}/_ext/203301211/report.o ${OBJECTDIR}/_ext/203301211/stepper_pic32.o ${OBJECTDIR}/_ext/203301211/planner.o ${OBJECTDIR}/_ext/203301211/eeprom_pic32.o ${OBJECTDIR}/_ext/203301211/eeprom.o ${OBJECTDIR}/_ext/203301211/probe.o ${OBJECTDIR}/_ext/203301211/nuts_bolts_pic32.o ${OBJECTDIR}/_ext/203301211/spindle_control_pic32.o ${OBJECTDIR}/_ext/203301211/coolant_control.o ${OBJECTDIR}/_ext/203301211/print.o ${OBJECTDIR}/_ext/203301211/gcode.o ${OBJECTDIR}/_ext/203301211/motion_control.o ${OBJECTDIR}/_ext/203301211/protocol.o ${OBJECTDIR}/_ext/203301211/serial.o ${OBJECTDIR}/_ext/203301211/serial_pic32.o ${OBJECTDIR}/_ext/203301211/spindle_control.o ${OBJECTDIR}/_ext/203301211/system.o ${OBJECTDIR}/_ext/203301211/nuts_bolts.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/203301211/main.o.d ${OBJECTDIR}/_ext/203301211/stepper.o.d ${OBJECTDIR}/_ext/203301211/eeprom_in_ram.o.d ${OBJECTDIR}/_ext/203301211/system_pic32.o.d ${OBJECTDIR}/_ext/203301211/limits.o.d ${OBJECTDIR}/_ext/203301211/settings.o.d ${OBJECTDIR}/_ext/203301211/report.o.d ${OBJECTDIR}/_ext/203301211/stepper_pic32.o.d ${OBJECTDIR}/_ext/203301211/planner.o.d ${OBJECTDIR}/_ext/203301211/eeprom_pic32.o.d ${OBJECTDIR}/_ext/203301211/eeprom.o.d ${OBJECTDIR}/_ext/203301211/probe.o.d ${OBJECTDIR}/_ext/203301211/nuts_bolts_pic32.o.d ${OBJECTDIR}/_ext/203301211/spindle_control_pic32.o.d ${OBJECTDIR}/_ext/203301211/coolant_control.o.d ${OBJECTDIR}/_ext/203301211/print.o.d ${OBJECTDIR}/_ext/203301211/gcode.o.d ${OBJECTDIR}/_ext/203301211/motion_control.o.d ${OBJECTDIR}/_ext/203301211/protocol.o.d ${OBJECTDIR}/_ext/203301211/serial.o.d ${OBJECTDIR}/_ext/203301211/serial_pic32.o.d ${OBJECTDIR}/_ext/203301211/spindle_control.o.d ${OBJECTDIR}/_ext/203301211/system.o.d ${OBJECTDIR}/_ext/203301211/nuts_bolts.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/203301211/main.o ${OBJECTDIR}/_ext/203301211/stepper.o ${OBJECTDIR}/_ext/203301211/eeprom_in_ram.o ${OBJECTDIR}/_ext/203301211/system_pic32.o ${OBJECTDIR}/_ext/203301211/limits.o ${OBJECTDIR}/_ext/203301211/settings.o ${OBJECTDIR}/_ext/203301211/report.o ${OBJECTDIR}/_ext/203301211/stepper_pic32.o ${OBJECTDIR}/_ext/203301211/planner.o ${OBJECTDIR}/_ext/203301211/eeprom_pic32.o ${OBJECTDIR}/_ext/203301211/eeprom.o ${OBJECTDIR}/_ext/203301211/probe.o ${OBJECTDIR}/_ext/203301211/nuts_bolts_pic32.o ${OBJECTDIR}/_ext/203301211/spindle_control_pic32.o ${OBJECTDIR}/_ext/203301211/coolant_control.o ${OBJECTDIR}/_ext/203301211/print.o ${OBJECTDIR}/_ext/203301211/gcode.o ${OBJECTDIR}/_ext/203301211/motion_control.o ${OBJECTDIR}/_ext/203301211/protocol.o ${OBJECTDIR}/_ext/203301211/serial.o ${OBJECTDIR}/_ext/203301211/serial_pic32.o ${OBJECTDIR}/_ext/203301211/spindle_control.o ${OBJECTDIR}/_ext/203301211/system.o ${OBJECTDIR}/_ext/203301211/nuts_bolts.o

# Source Files
SOURCEFILES=/home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/main.c /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/stepper.c /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/eeprom_in_ram.c /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/system_pic32.c /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/limits.c /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/settings.c /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/report.c /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/stepper_pic32.c /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/planner.c /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/eeprom_pic32.c /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/eeprom.c /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/probe.c /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/nuts_bolts_pic32.c /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/spindle_control_pic32.c /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/coolant_control.c /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/print.c /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/gcode.c /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/motion_control.c /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/protocol.c /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/serial.c /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/serial_pic32.c /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/spindle_control.c /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/system.c /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/nuts_bolts.c



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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/grbl_test1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX170F256B
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/203301211/main.o: /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/203301211" 
	@${RM} ${OBJECTDIR}/_ext/203301211/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/203301211/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/203301211/main.o.d" -o ${OBJECTDIR}/_ext/203301211/main.o /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/main.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/_ext/203301211/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/203301211/stepper.o: /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/stepper.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/203301211" 
	@${RM} ${OBJECTDIR}/_ext/203301211/stepper.o.d 
	@${RM} ${OBJECTDIR}/_ext/203301211/stepper.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/203301211/stepper.o.d" -o ${OBJECTDIR}/_ext/203301211/stepper.o /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/stepper.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/_ext/203301211/stepper.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/203301211/eeprom_in_ram.o: /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/eeprom_in_ram.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/203301211" 
	@${RM} ${OBJECTDIR}/_ext/203301211/eeprom_in_ram.o.d 
	@${RM} ${OBJECTDIR}/_ext/203301211/eeprom_in_ram.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/203301211/eeprom_in_ram.o.d" -o ${OBJECTDIR}/_ext/203301211/eeprom_in_ram.o /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/eeprom_in_ram.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/_ext/203301211/eeprom_in_ram.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/203301211/system_pic32.o: /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/system_pic32.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/203301211" 
	@${RM} ${OBJECTDIR}/_ext/203301211/system_pic32.o.d 
	@${RM} ${OBJECTDIR}/_ext/203301211/system_pic32.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/203301211/system_pic32.o.d" -o ${OBJECTDIR}/_ext/203301211/system_pic32.o /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/system_pic32.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/_ext/203301211/system_pic32.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/203301211/limits.o: /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/limits.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/203301211" 
	@${RM} ${OBJECTDIR}/_ext/203301211/limits.o.d 
	@${RM} ${OBJECTDIR}/_ext/203301211/limits.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/203301211/limits.o.d" -o ${OBJECTDIR}/_ext/203301211/limits.o /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/limits.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/_ext/203301211/limits.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/203301211/settings.o: /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/settings.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/203301211" 
	@${RM} ${OBJECTDIR}/_ext/203301211/settings.o.d 
	@${RM} ${OBJECTDIR}/_ext/203301211/settings.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/203301211/settings.o.d" -o ${OBJECTDIR}/_ext/203301211/settings.o /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/settings.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/_ext/203301211/settings.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/203301211/report.o: /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/report.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/203301211" 
	@${RM} ${OBJECTDIR}/_ext/203301211/report.o.d 
	@${RM} ${OBJECTDIR}/_ext/203301211/report.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/203301211/report.o.d" -o ${OBJECTDIR}/_ext/203301211/report.o /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/report.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/_ext/203301211/report.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/203301211/stepper_pic32.o: /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/stepper_pic32.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/203301211" 
	@${RM} ${OBJECTDIR}/_ext/203301211/stepper_pic32.o.d 
	@${RM} ${OBJECTDIR}/_ext/203301211/stepper_pic32.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/203301211/stepper_pic32.o.d" -o ${OBJECTDIR}/_ext/203301211/stepper_pic32.o /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/stepper_pic32.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/_ext/203301211/stepper_pic32.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/203301211/planner.o: /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/planner.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/203301211" 
	@${RM} ${OBJECTDIR}/_ext/203301211/planner.o.d 
	@${RM} ${OBJECTDIR}/_ext/203301211/planner.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/203301211/planner.o.d" -o ${OBJECTDIR}/_ext/203301211/planner.o /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/planner.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/_ext/203301211/planner.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/203301211/eeprom_pic32.o: /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/eeprom_pic32.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/203301211" 
	@${RM} ${OBJECTDIR}/_ext/203301211/eeprom_pic32.o.d 
	@${RM} ${OBJECTDIR}/_ext/203301211/eeprom_pic32.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/203301211/eeprom_pic32.o.d" -o ${OBJECTDIR}/_ext/203301211/eeprom_pic32.o /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/eeprom_pic32.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/_ext/203301211/eeprom_pic32.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/203301211/eeprom.o: /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/eeprom.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/203301211" 
	@${RM} ${OBJECTDIR}/_ext/203301211/eeprom.o.d 
	@${RM} ${OBJECTDIR}/_ext/203301211/eeprom.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/203301211/eeprom.o.d" -o ${OBJECTDIR}/_ext/203301211/eeprom.o /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/eeprom.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/_ext/203301211/eeprom.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/203301211/probe.o: /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/probe.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/203301211" 
	@${RM} ${OBJECTDIR}/_ext/203301211/probe.o.d 
	@${RM} ${OBJECTDIR}/_ext/203301211/probe.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/203301211/probe.o.d" -o ${OBJECTDIR}/_ext/203301211/probe.o /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/probe.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/_ext/203301211/probe.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/203301211/nuts_bolts_pic32.o: /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/nuts_bolts_pic32.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/203301211" 
	@${RM} ${OBJECTDIR}/_ext/203301211/nuts_bolts_pic32.o.d 
	@${RM} ${OBJECTDIR}/_ext/203301211/nuts_bolts_pic32.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/203301211/nuts_bolts_pic32.o.d" -o ${OBJECTDIR}/_ext/203301211/nuts_bolts_pic32.o /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/nuts_bolts_pic32.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/_ext/203301211/nuts_bolts_pic32.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/203301211/spindle_control_pic32.o: /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/spindle_control_pic32.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/203301211" 
	@${RM} ${OBJECTDIR}/_ext/203301211/spindle_control_pic32.o.d 
	@${RM} ${OBJECTDIR}/_ext/203301211/spindle_control_pic32.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/203301211/spindle_control_pic32.o.d" -o ${OBJECTDIR}/_ext/203301211/spindle_control_pic32.o /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/spindle_control_pic32.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/_ext/203301211/spindle_control_pic32.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/203301211/coolant_control.o: /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/coolant_control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/203301211" 
	@${RM} ${OBJECTDIR}/_ext/203301211/coolant_control.o.d 
	@${RM} ${OBJECTDIR}/_ext/203301211/coolant_control.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/203301211/coolant_control.o.d" -o ${OBJECTDIR}/_ext/203301211/coolant_control.o /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/coolant_control.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/_ext/203301211/coolant_control.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/203301211/print.o: /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/print.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/203301211" 
	@${RM} ${OBJECTDIR}/_ext/203301211/print.o.d 
	@${RM} ${OBJECTDIR}/_ext/203301211/print.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/203301211/print.o.d" -o ${OBJECTDIR}/_ext/203301211/print.o /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/print.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/_ext/203301211/print.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/203301211/gcode.o: /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/gcode.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/203301211" 
	@${RM} ${OBJECTDIR}/_ext/203301211/gcode.o.d 
	@${RM} ${OBJECTDIR}/_ext/203301211/gcode.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/203301211/gcode.o.d" -o ${OBJECTDIR}/_ext/203301211/gcode.o /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/gcode.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/_ext/203301211/gcode.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/203301211/motion_control.o: /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/motion_control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/203301211" 
	@${RM} ${OBJECTDIR}/_ext/203301211/motion_control.o.d 
	@${RM} ${OBJECTDIR}/_ext/203301211/motion_control.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/203301211/motion_control.o.d" -o ${OBJECTDIR}/_ext/203301211/motion_control.o /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/motion_control.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/_ext/203301211/motion_control.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/203301211/protocol.o: /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/protocol.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/203301211" 
	@${RM} ${OBJECTDIR}/_ext/203301211/protocol.o.d 
	@${RM} ${OBJECTDIR}/_ext/203301211/protocol.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/203301211/protocol.o.d" -o ${OBJECTDIR}/_ext/203301211/protocol.o /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/protocol.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/_ext/203301211/protocol.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/203301211/serial.o: /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/serial.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/203301211" 
	@${RM} ${OBJECTDIR}/_ext/203301211/serial.o.d 
	@${RM} ${OBJECTDIR}/_ext/203301211/serial.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/203301211/serial.o.d" -o ${OBJECTDIR}/_ext/203301211/serial.o /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/serial.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/_ext/203301211/serial.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/203301211/serial_pic32.o: /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/serial_pic32.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/203301211" 
	@${RM} ${OBJECTDIR}/_ext/203301211/serial_pic32.o.d 
	@${RM} ${OBJECTDIR}/_ext/203301211/serial_pic32.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/203301211/serial_pic32.o.d" -o ${OBJECTDIR}/_ext/203301211/serial_pic32.o /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/serial_pic32.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/_ext/203301211/serial_pic32.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/203301211/spindle_control.o: /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/spindle_control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/203301211" 
	@${RM} ${OBJECTDIR}/_ext/203301211/spindle_control.o.d 
	@${RM} ${OBJECTDIR}/_ext/203301211/spindle_control.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/203301211/spindle_control.o.d" -o ${OBJECTDIR}/_ext/203301211/spindle_control.o /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/spindle_control.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/_ext/203301211/spindle_control.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/203301211/system.o: /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/system.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/203301211" 
	@${RM} ${OBJECTDIR}/_ext/203301211/system.o.d 
	@${RM} ${OBJECTDIR}/_ext/203301211/system.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/203301211/system.o.d" -o ${OBJECTDIR}/_ext/203301211/system.o /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/system.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/_ext/203301211/system.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/203301211/nuts_bolts.o: /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/nuts_bolts.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/203301211" 
	@${RM} ${OBJECTDIR}/_ext/203301211/nuts_bolts.o.d 
	@${RM} ${OBJECTDIR}/_ext/203301211/nuts_bolts.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/203301211/nuts_bolts.o.d" -o ${OBJECTDIR}/_ext/203301211/nuts_bolts.o /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/nuts_bolts.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/_ext/203301211/nuts_bolts.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/_ext/203301211/main.o: /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/203301211" 
	@${RM} ${OBJECTDIR}/_ext/203301211/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/203301211/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/203301211/main.o.d" -o ${OBJECTDIR}/_ext/203301211/main.o /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/main.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/_ext/203301211/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/203301211/stepper.o: /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/stepper.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/203301211" 
	@${RM} ${OBJECTDIR}/_ext/203301211/stepper.o.d 
	@${RM} ${OBJECTDIR}/_ext/203301211/stepper.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/203301211/stepper.o.d" -o ${OBJECTDIR}/_ext/203301211/stepper.o /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/stepper.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/_ext/203301211/stepper.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/203301211/eeprom_in_ram.o: /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/eeprom_in_ram.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/203301211" 
	@${RM} ${OBJECTDIR}/_ext/203301211/eeprom_in_ram.o.d 
	@${RM} ${OBJECTDIR}/_ext/203301211/eeprom_in_ram.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/203301211/eeprom_in_ram.o.d" -o ${OBJECTDIR}/_ext/203301211/eeprom_in_ram.o /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/eeprom_in_ram.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/_ext/203301211/eeprom_in_ram.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/203301211/system_pic32.o: /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/system_pic32.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/203301211" 
	@${RM} ${OBJECTDIR}/_ext/203301211/system_pic32.o.d 
	@${RM} ${OBJECTDIR}/_ext/203301211/system_pic32.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/203301211/system_pic32.o.d" -o ${OBJECTDIR}/_ext/203301211/system_pic32.o /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/system_pic32.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/_ext/203301211/system_pic32.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/203301211/limits.o: /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/limits.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/203301211" 
	@${RM} ${OBJECTDIR}/_ext/203301211/limits.o.d 
	@${RM} ${OBJECTDIR}/_ext/203301211/limits.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/203301211/limits.o.d" -o ${OBJECTDIR}/_ext/203301211/limits.o /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/limits.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/_ext/203301211/limits.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/203301211/settings.o: /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/settings.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/203301211" 
	@${RM} ${OBJECTDIR}/_ext/203301211/settings.o.d 
	@${RM} ${OBJECTDIR}/_ext/203301211/settings.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/203301211/settings.o.d" -o ${OBJECTDIR}/_ext/203301211/settings.o /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/settings.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/_ext/203301211/settings.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/203301211/report.o: /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/report.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/203301211" 
	@${RM} ${OBJECTDIR}/_ext/203301211/report.o.d 
	@${RM} ${OBJECTDIR}/_ext/203301211/report.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/203301211/report.o.d" -o ${OBJECTDIR}/_ext/203301211/report.o /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/report.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/_ext/203301211/report.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/203301211/stepper_pic32.o: /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/stepper_pic32.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/203301211" 
	@${RM} ${OBJECTDIR}/_ext/203301211/stepper_pic32.o.d 
	@${RM} ${OBJECTDIR}/_ext/203301211/stepper_pic32.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/203301211/stepper_pic32.o.d" -o ${OBJECTDIR}/_ext/203301211/stepper_pic32.o /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/stepper_pic32.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/_ext/203301211/stepper_pic32.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/203301211/planner.o: /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/planner.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/203301211" 
	@${RM} ${OBJECTDIR}/_ext/203301211/planner.o.d 
	@${RM} ${OBJECTDIR}/_ext/203301211/planner.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/203301211/planner.o.d" -o ${OBJECTDIR}/_ext/203301211/planner.o /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/planner.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/_ext/203301211/planner.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/203301211/eeprom_pic32.o: /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/eeprom_pic32.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/203301211" 
	@${RM} ${OBJECTDIR}/_ext/203301211/eeprom_pic32.o.d 
	@${RM} ${OBJECTDIR}/_ext/203301211/eeprom_pic32.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/203301211/eeprom_pic32.o.d" -o ${OBJECTDIR}/_ext/203301211/eeprom_pic32.o /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/eeprom_pic32.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/_ext/203301211/eeprom_pic32.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/203301211/eeprom.o: /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/eeprom.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/203301211" 
	@${RM} ${OBJECTDIR}/_ext/203301211/eeprom.o.d 
	@${RM} ${OBJECTDIR}/_ext/203301211/eeprom.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/203301211/eeprom.o.d" -o ${OBJECTDIR}/_ext/203301211/eeprom.o /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/eeprom.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/_ext/203301211/eeprom.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/203301211/probe.o: /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/probe.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/203301211" 
	@${RM} ${OBJECTDIR}/_ext/203301211/probe.o.d 
	@${RM} ${OBJECTDIR}/_ext/203301211/probe.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/203301211/probe.o.d" -o ${OBJECTDIR}/_ext/203301211/probe.o /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/probe.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/_ext/203301211/probe.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/203301211/nuts_bolts_pic32.o: /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/nuts_bolts_pic32.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/203301211" 
	@${RM} ${OBJECTDIR}/_ext/203301211/nuts_bolts_pic32.o.d 
	@${RM} ${OBJECTDIR}/_ext/203301211/nuts_bolts_pic32.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/203301211/nuts_bolts_pic32.o.d" -o ${OBJECTDIR}/_ext/203301211/nuts_bolts_pic32.o /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/nuts_bolts_pic32.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/_ext/203301211/nuts_bolts_pic32.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/203301211/spindle_control_pic32.o: /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/spindle_control_pic32.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/203301211" 
	@${RM} ${OBJECTDIR}/_ext/203301211/spindle_control_pic32.o.d 
	@${RM} ${OBJECTDIR}/_ext/203301211/spindle_control_pic32.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/203301211/spindle_control_pic32.o.d" -o ${OBJECTDIR}/_ext/203301211/spindle_control_pic32.o /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/spindle_control_pic32.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/_ext/203301211/spindle_control_pic32.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/203301211/coolant_control.o: /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/coolant_control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/203301211" 
	@${RM} ${OBJECTDIR}/_ext/203301211/coolant_control.o.d 
	@${RM} ${OBJECTDIR}/_ext/203301211/coolant_control.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/203301211/coolant_control.o.d" -o ${OBJECTDIR}/_ext/203301211/coolant_control.o /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/coolant_control.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/_ext/203301211/coolant_control.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/203301211/print.o: /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/print.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/203301211" 
	@${RM} ${OBJECTDIR}/_ext/203301211/print.o.d 
	@${RM} ${OBJECTDIR}/_ext/203301211/print.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/203301211/print.o.d" -o ${OBJECTDIR}/_ext/203301211/print.o /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/print.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/_ext/203301211/print.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/203301211/gcode.o: /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/gcode.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/203301211" 
	@${RM} ${OBJECTDIR}/_ext/203301211/gcode.o.d 
	@${RM} ${OBJECTDIR}/_ext/203301211/gcode.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/203301211/gcode.o.d" -o ${OBJECTDIR}/_ext/203301211/gcode.o /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/gcode.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/_ext/203301211/gcode.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/203301211/motion_control.o: /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/motion_control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/203301211" 
	@${RM} ${OBJECTDIR}/_ext/203301211/motion_control.o.d 
	@${RM} ${OBJECTDIR}/_ext/203301211/motion_control.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/203301211/motion_control.o.d" -o ${OBJECTDIR}/_ext/203301211/motion_control.o /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/motion_control.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/_ext/203301211/motion_control.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/203301211/protocol.o: /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/protocol.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/203301211" 
	@${RM} ${OBJECTDIR}/_ext/203301211/protocol.o.d 
	@${RM} ${OBJECTDIR}/_ext/203301211/protocol.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/203301211/protocol.o.d" -o ${OBJECTDIR}/_ext/203301211/protocol.o /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/protocol.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/_ext/203301211/protocol.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/203301211/serial.o: /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/serial.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/203301211" 
	@${RM} ${OBJECTDIR}/_ext/203301211/serial.o.d 
	@${RM} ${OBJECTDIR}/_ext/203301211/serial.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/203301211/serial.o.d" -o ${OBJECTDIR}/_ext/203301211/serial.o /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/serial.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/_ext/203301211/serial.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/203301211/serial_pic32.o: /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/serial_pic32.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/203301211" 
	@${RM} ${OBJECTDIR}/_ext/203301211/serial_pic32.o.d 
	@${RM} ${OBJECTDIR}/_ext/203301211/serial_pic32.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/203301211/serial_pic32.o.d" -o ${OBJECTDIR}/_ext/203301211/serial_pic32.o /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/serial_pic32.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/_ext/203301211/serial_pic32.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/203301211/spindle_control.o: /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/spindle_control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/203301211" 
	@${RM} ${OBJECTDIR}/_ext/203301211/spindle_control.o.d 
	@${RM} ${OBJECTDIR}/_ext/203301211/spindle_control.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/203301211/spindle_control.o.d" -o ${OBJECTDIR}/_ext/203301211/spindle_control.o /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/spindle_control.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/_ext/203301211/spindle_control.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/203301211/system.o: /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/system.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/203301211" 
	@${RM} ${OBJECTDIR}/_ext/203301211/system.o.d 
	@${RM} ${OBJECTDIR}/_ext/203301211/system.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/203301211/system.o.d" -o ${OBJECTDIR}/_ext/203301211/system.o /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/system.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/_ext/203301211/system.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/203301211/nuts_bolts.o: /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/nuts_bolts.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/203301211" 
	@${RM} ${OBJECTDIR}/_ext/203301211/nuts_bolts.o.d 
	@${RM} ${OBJECTDIR}/_ext/203301211/nuts_bolts.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/203301211/nuts_bolts.o.d" -o ${OBJECTDIR}/_ext/203301211/nuts_bolts.o /home/dev-user/Projects/Personal/PIC/grbl_test1.X/grbl/nuts_bolts.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/_ext/203301211/nuts_bolts.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/grbl_test1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g   -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/grbl_test1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC00490:0x1FC00BEF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -mdfp="${DFP_DIR}"
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/grbl_test1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/grbl_test1.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -mdfp="${DFP_DIR}"
	${MP_CC_DIR}/xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/grbl_test1.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
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

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
