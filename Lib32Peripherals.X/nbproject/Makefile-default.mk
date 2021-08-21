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
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Lib32Peripherals.X.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=a
DEBUGGABLE_SUFFIX=
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Lib32Peripherals.X.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=/home/dev1/Projects/PIC/Lib32Peripherals.X/Timers.c /home/dev1/Projects/PIC/Lib32Peripherals.X/Uart.c /home/dev1/Projects/PIC/Lib32Peripherals.X/I2C.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1182535385/Timers.o ${OBJECTDIR}/_ext/1182535385/Uart.o ${OBJECTDIR}/_ext/1182535385/I2C.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1182535385/Timers.o.d ${OBJECTDIR}/_ext/1182535385/Uart.o.d ${OBJECTDIR}/_ext/1182535385/I2C.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1182535385/Timers.o ${OBJECTDIR}/_ext/1182535385/Uart.o ${OBJECTDIR}/_ext/1182535385/I2C.o

# Source Files
SOURCEFILES=/home/dev1/Projects/PIC/Lib32Peripherals.X/Timers.c /home/dev1/Projects/PIC/Lib32Peripherals.X/Uart.c /home/dev1/Projects/PIC/Lib32Peripherals.X/I2C.c



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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/Lib32Peripherals.X.${OUTPUT_SUFFIX}

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
${OBJECTDIR}/_ext/1182535385/Timers.o: /home/dev1/Projects/PIC/Lib32Peripherals.X/Timers.c  .generated_files/a0f755534895dfcd496cb09f8bfe7d8ae1b063f8.flag .generated_files/71b2fa7f85a22426d8b136d9a94b6b5776fdc3b0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1182535385" 
	@${RM} ${OBJECTDIR}/_ext/1182535385/Timers.o.d 
	@${RM} ${OBJECTDIR}/_ext/1182535385/Timers.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1182535385/Timers.o.d" -o ${OBJECTDIR}/_ext/1182535385/Timers.o /home/dev1/Projects/PIC/Lib32Peripherals.X/Timers.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1182535385/Uart.o: /home/dev1/Projects/PIC/Lib32Peripherals.X/Uart.c  .generated_files/eabc54a8c5ab69a13eadf1cc5315acbba72654d5.flag .generated_files/71b2fa7f85a22426d8b136d9a94b6b5776fdc3b0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1182535385" 
	@${RM} ${OBJECTDIR}/_ext/1182535385/Uart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1182535385/Uart.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1182535385/Uart.o.d" -o ${OBJECTDIR}/_ext/1182535385/Uart.o /home/dev1/Projects/PIC/Lib32Peripherals.X/Uart.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1182535385/I2C.o: /home/dev1/Projects/PIC/Lib32Peripherals.X/I2C.c  .generated_files/16aedc95a1275828e2bbf795265660a79c82e838.flag .generated_files/71b2fa7f85a22426d8b136d9a94b6b5776fdc3b0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1182535385" 
	@${RM} ${OBJECTDIR}/_ext/1182535385/I2C.o.d 
	@${RM} ${OBJECTDIR}/_ext/1182535385/I2C.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1182535385/I2C.o.d" -o ${OBJECTDIR}/_ext/1182535385/I2C.o /home/dev1/Projects/PIC/Lib32Peripherals.X/I2C.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
else
${OBJECTDIR}/_ext/1182535385/Timers.o: /home/dev1/Projects/PIC/Lib32Peripherals.X/Timers.c  .generated_files/1e829f7bb6db187cff8adbd09e3fa8434578a5ae.flag .generated_files/71b2fa7f85a22426d8b136d9a94b6b5776fdc3b0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1182535385" 
	@${RM} ${OBJECTDIR}/_ext/1182535385/Timers.o.d 
	@${RM} ${OBJECTDIR}/_ext/1182535385/Timers.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1182535385/Timers.o.d" -o ${OBJECTDIR}/_ext/1182535385/Timers.o /home/dev1/Projects/PIC/Lib32Peripherals.X/Timers.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1182535385/Uart.o: /home/dev1/Projects/PIC/Lib32Peripherals.X/Uart.c  .generated_files/805f87e4b5005572e641faf55dad48e9d09adab4.flag .generated_files/71b2fa7f85a22426d8b136d9a94b6b5776fdc3b0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1182535385" 
	@${RM} ${OBJECTDIR}/_ext/1182535385/Uart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1182535385/Uart.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1182535385/Uart.o.d" -o ${OBJECTDIR}/_ext/1182535385/Uart.o /home/dev1/Projects/PIC/Lib32Peripherals.X/Uart.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1182535385/I2C.o: /home/dev1/Projects/PIC/Lib32Peripherals.X/I2C.c  .generated_files/a4122f9e5b17c735ef2648ed11f52cbf3ceab0fb.flag .generated_files/71b2fa7f85a22426d8b136d9a94b6b5776fdc3b0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1182535385" 
	@${RM} ${OBJECTDIR}/_ext/1182535385/I2C.o.d 
	@${RM} ${OBJECTDIR}/_ext/1182535385/I2C.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1182535385/I2C.o.d" -o ${OBJECTDIR}/_ext/1182535385/I2C.o /home/dev1/Projects/PIC/Lib32Peripherals.X/I2C.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: archive
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Lib32Peripherals.X.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_AR} $(MP_EXTRA_AR_PRE)  r dist/${CND_CONF}/${IMAGE_TYPE}/Lib32Peripherals.X.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    
else
dist/${CND_CONF}/${IMAGE_TYPE}/Lib32Peripherals.X.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_AR} $(MP_EXTRA_AR_PRE)  r dist/${CND_CONF}/${IMAGE_TYPE}/Lib32Peripherals.X.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    
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
