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
OUTPUT_SUFFIX=a
DEBUGGABLE_SUFFIX=
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/LibOutputDevices.X.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=a
DEBUGGABLE_SUFFIX=
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/LibOutputDevices.X.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=/home/dev1/Projects/PIC/LibOutputDevices.X/disp_7seg4dig.c /home/dev1/Projects/PIC/LibOutputDevices.X/servo.c /home/dev1/Projects/PIC/LibOutputDevices.X/stepper.c /home/dev1/Projects/PIC/LibOutputDevices.X/Oled.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/130494665/disp_7seg4dig.o ${OBJECTDIR}/_ext/130494665/servo.o ${OBJECTDIR}/_ext/130494665/stepper.o ${OBJECTDIR}/_ext/130494665/Oled.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/130494665/disp_7seg4dig.o.d ${OBJECTDIR}/_ext/130494665/servo.o.d ${OBJECTDIR}/_ext/130494665/stepper.o.d ${OBJECTDIR}/_ext/130494665/Oled.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/130494665/disp_7seg4dig.o ${OBJECTDIR}/_ext/130494665/servo.o ${OBJECTDIR}/_ext/130494665/stepper.o ${OBJECTDIR}/_ext/130494665/Oled.o

# Source Files
SOURCEFILES=/home/dev1/Projects/PIC/LibOutputDevices.X/disp_7seg4dig.c /home/dev1/Projects/PIC/LibOutputDevices.X/servo.c /home/dev1/Projects/PIC/LibOutputDevices.X/stepper.c /home/dev1/Projects/PIC/LibOutputDevices.X/Oled.c



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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/LibOutputDevices.X.${OUTPUT_SUFFIX}

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
${OBJECTDIR}/_ext/130494665/disp_7seg4dig.o: /home/dev1/Projects/PIC/LibOutputDevices.X/disp_7seg4dig.c  .generated_files/cbeec6fc0daa868d6e28369329966f4cc0be7b43.flag .generated_files/71b2fa7f85a22426d8b136d9a94b6b5776fdc3b0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/130494665" 
	@${RM} ${OBJECTDIR}/_ext/130494665/disp_7seg4dig.o.d 
	@${RM} ${OBJECTDIR}/_ext/130494665/disp_7seg4dig.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/130494665/disp_7seg4dig.o.d" -o ${OBJECTDIR}/_ext/130494665/disp_7seg4dig.o /home/dev1/Projects/PIC/LibOutputDevices.X/disp_7seg4dig.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/130494665/servo.o: /home/dev1/Projects/PIC/LibOutputDevices.X/servo.c  .generated_files/53422b8aab7dffe604b3b91658c286229024ba69.flag .generated_files/71b2fa7f85a22426d8b136d9a94b6b5776fdc3b0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/130494665" 
	@${RM} ${OBJECTDIR}/_ext/130494665/servo.o.d 
	@${RM} ${OBJECTDIR}/_ext/130494665/servo.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/130494665/servo.o.d" -o ${OBJECTDIR}/_ext/130494665/servo.o /home/dev1/Projects/PIC/LibOutputDevices.X/servo.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/130494665/stepper.o: /home/dev1/Projects/PIC/LibOutputDevices.X/stepper.c  .generated_files/86b208ce837f04a3c2c92ce58c0fd9e02ae50b95.flag .generated_files/71b2fa7f85a22426d8b136d9a94b6b5776fdc3b0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/130494665" 
	@${RM} ${OBJECTDIR}/_ext/130494665/stepper.o.d 
	@${RM} ${OBJECTDIR}/_ext/130494665/stepper.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/130494665/stepper.o.d" -o ${OBJECTDIR}/_ext/130494665/stepper.o /home/dev1/Projects/PIC/LibOutputDevices.X/stepper.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/130494665/Oled.o: /home/dev1/Projects/PIC/LibOutputDevices.X/Oled.c  .generated_files/aec8d0e0c437cb3469649ca5a45f1cf239d67c2d.flag .generated_files/71b2fa7f85a22426d8b136d9a94b6b5776fdc3b0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/130494665" 
	@${RM} ${OBJECTDIR}/_ext/130494665/Oled.o.d 
	@${RM} ${OBJECTDIR}/_ext/130494665/Oled.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/130494665/Oled.o.d" -o ${OBJECTDIR}/_ext/130494665/Oled.o /home/dev1/Projects/PIC/LibOutputDevices.X/Oled.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
else
${OBJECTDIR}/_ext/130494665/disp_7seg4dig.o: /home/dev1/Projects/PIC/LibOutputDevices.X/disp_7seg4dig.c  .generated_files/90c3ba799a258d5951204c4ef88ee8b2692a1bd4.flag .generated_files/71b2fa7f85a22426d8b136d9a94b6b5776fdc3b0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/130494665" 
	@${RM} ${OBJECTDIR}/_ext/130494665/disp_7seg4dig.o.d 
	@${RM} ${OBJECTDIR}/_ext/130494665/disp_7seg4dig.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/130494665/disp_7seg4dig.o.d" -o ${OBJECTDIR}/_ext/130494665/disp_7seg4dig.o /home/dev1/Projects/PIC/LibOutputDevices.X/disp_7seg4dig.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/130494665/servo.o: /home/dev1/Projects/PIC/LibOutputDevices.X/servo.c  .generated_files/48c5ba8a8ef10d88b0385edf664c528953b11739.flag .generated_files/71b2fa7f85a22426d8b136d9a94b6b5776fdc3b0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/130494665" 
	@${RM} ${OBJECTDIR}/_ext/130494665/servo.o.d 
	@${RM} ${OBJECTDIR}/_ext/130494665/servo.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/130494665/servo.o.d" -o ${OBJECTDIR}/_ext/130494665/servo.o /home/dev1/Projects/PIC/LibOutputDevices.X/servo.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/130494665/stepper.o: /home/dev1/Projects/PIC/LibOutputDevices.X/stepper.c  .generated_files/1df1c7ae09899fb6d96a87e26b18ce8f5befe0ad.flag .generated_files/71b2fa7f85a22426d8b136d9a94b6b5776fdc3b0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/130494665" 
	@${RM} ${OBJECTDIR}/_ext/130494665/stepper.o.d 
	@${RM} ${OBJECTDIR}/_ext/130494665/stepper.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/130494665/stepper.o.d" -o ${OBJECTDIR}/_ext/130494665/stepper.o /home/dev1/Projects/PIC/LibOutputDevices.X/stepper.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/130494665/Oled.o: /home/dev1/Projects/PIC/LibOutputDevices.X/Oled.c  .generated_files/25018c6f1f525dc18ffa51b69a4b04eb7d1b9258.flag .generated_files/71b2fa7f85a22426d8b136d9a94b6b5776fdc3b0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/130494665" 
	@${RM} ${OBJECTDIR}/_ext/130494665/Oled.o.d 
	@${RM} ${OBJECTDIR}/_ext/130494665/Oled.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/130494665/Oled.o.d" -o ${OBJECTDIR}/_ext/130494665/Oled.o /home/dev1/Projects/PIC/LibOutputDevices.X/Oled.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: archive
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/LibOutputDevices.X.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_AR} $(MP_EXTRA_AR_PRE)  r dist/${CND_CONF}/${IMAGE_TYPE}/LibOutputDevices.X.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    
else
dist/${CND_CONF}/${IMAGE_TYPE}/LibOutputDevices.X.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_AR} $(MP_EXTRA_AR_PRE)  r dist/${CND_CONF}/${IMAGE_TYPE}/LibOutputDevices.X.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    
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
