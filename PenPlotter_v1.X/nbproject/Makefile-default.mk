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
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/PenPlotter_v1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/PenPlotter_v1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=/home/dev-user/Projects/Personal/PIC/PenPlotter_v1.X/main.c /home/dev-user/Projects/Personal/PIC/PenPlotter_v1.X/System.c /home/dev-user/Projects/Personal/PIC/PenPlotter_v1.X/Interrupts.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/837956845/main.o ${OBJECTDIR}/_ext/837956845/System.o ${OBJECTDIR}/_ext/837956845/Interrupts.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/837956845/main.o.d ${OBJECTDIR}/_ext/837956845/System.o.d ${OBJECTDIR}/_ext/837956845/Interrupts.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/837956845/main.o ${OBJECTDIR}/_ext/837956845/System.o ${OBJECTDIR}/_ext/837956845/Interrupts.o

# Source Files
SOURCEFILES=/home/dev-user/Projects/Personal/PIC/PenPlotter_v1.X/main.c /home/dev-user/Projects/Personal/PIC/PenPlotter_v1.X/System.c /home/dev-user/Projects/Personal/PIC/PenPlotter_v1.X/Interrupts.c



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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/PenPlotter_v1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

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
${OBJECTDIR}/_ext/837956845/main.o: /home/dev-user/Projects/Personal/PIC/PenPlotter_v1.X/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/837956845" 
	@${RM} ${OBJECTDIR}/_ext/837956845/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/837956845/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/837956845/main.o.d" -o ${OBJECTDIR}/_ext/837956845/main.o /home/dev-user/Projects/Personal/PIC/PenPlotter_v1.X/main.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/_ext/837956845/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/837956845/System.o: /home/dev-user/Projects/Personal/PIC/PenPlotter_v1.X/System.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/837956845" 
	@${RM} ${OBJECTDIR}/_ext/837956845/System.o.d 
	@${RM} ${OBJECTDIR}/_ext/837956845/System.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/837956845/System.o.d" -o ${OBJECTDIR}/_ext/837956845/System.o /home/dev-user/Projects/Personal/PIC/PenPlotter_v1.X/System.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/_ext/837956845/System.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/837956845/Interrupts.o: /home/dev-user/Projects/Personal/PIC/PenPlotter_v1.X/Interrupts.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/837956845" 
	@${RM} ${OBJECTDIR}/_ext/837956845/Interrupts.o.d 
	@${RM} ${OBJECTDIR}/_ext/837956845/Interrupts.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/837956845/Interrupts.o.d" -o ${OBJECTDIR}/_ext/837956845/Interrupts.o /home/dev-user/Projects/Personal/PIC/PenPlotter_v1.X/Interrupts.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/_ext/837956845/Interrupts.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/_ext/837956845/main.o: /home/dev-user/Projects/Personal/PIC/PenPlotter_v1.X/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/837956845" 
	@${RM} ${OBJECTDIR}/_ext/837956845/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/837956845/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/837956845/main.o.d" -o ${OBJECTDIR}/_ext/837956845/main.o /home/dev-user/Projects/Personal/PIC/PenPlotter_v1.X/main.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/_ext/837956845/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/837956845/System.o: /home/dev-user/Projects/Personal/PIC/PenPlotter_v1.X/System.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/837956845" 
	@${RM} ${OBJECTDIR}/_ext/837956845/System.o.d 
	@${RM} ${OBJECTDIR}/_ext/837956845/System.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/837956845/System.o.d" -o ${OBJECTDIR}/_ext/837956845/System.o /home/dev-user/Projects/Personal/PIC/PenPlotter_v1.X/System.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/_ext/837956845/System.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/837956845/Interrupts.o: /home/dev-user/Projects/Personal/PIC/PenPlotter_v1.X/Interrupts.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/837956845" 
	@${RM} ${OBJECTDIR}/_ext/837956845/Interrupts.o.d 
	@${RM} ${OBJECTDIR}/_ext/837956845/Interrupts.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/837956845/Interrupts.o.d" -o ${OBJECTDIR}/_ext/837956845/Interrupts.o /home/dev-user/Projects/Personal/PIC/PenPlotter_v1.X/Interrupts.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/_ext/837956845/Interrupts.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/PenPlotter_v1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  /home/dev-user/Projects/Personal/PIC/LibOutputDevices.X/dist/default/debug/LibOutputDevices.X.a /home/dev-user/Projects/Personal/PIC/LibMisc.X/dist/default/debug/LibMisc.X.a /home/dev-user/Projects/Personal/PIC/Lib32Peripherals.X/dist/default/debug/Lib32Peripherals.X.a  
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g   -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/PenPlotter_v1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    /home/dev-user/Projects/Personal/PIC/LibOutputDevices.X/dist/default/debug/LibOutputDevices.X.a /home/dev-user/Projects/Personal/PIC/LibMisc.X/dist/default/debug/LibMisc.X.a /home/dev-user/Projects/Personal/PIC/Lib32Peripherals.X/dist/default/debug/Lib32Peripherals.X.a      -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC00490:0x1FC00BEF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -mdfp="${DFP_DIR}"
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/PenPlotter_v1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  /home/dev-user/Projects/Personal/PIC/LibOutputDevices.X/dist/default/production/LibOutputDevices.X.a /home/dev-user/Projects/Personal/PIC/LibMisc.X/dist/default/production/LibMisc.X.a /home/dev-user/Projects/Personal/PIC/Lib32Peripherals.X/dist/default/production/Lib32Peripherals.X.a 
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/PenPlotter_v1.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    /home/dev-user/Projects/Personal/PIC/LibOutputDevices.X/dist/default/production/LibOutputDevices.X.a /home/dev-user/Projects/Personal/PIC/LibMisc.X/dist/default/production/LibMisc.X.a /home/dev-user/Projects/Personal/PIC/Lib32Peripherals.X/dist/default/production/Lib32Peripherals.X.a      -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -mdfp="${DFP_DIR}"
	${MP_CC_DIR}/xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/PenPlotter_v1.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:
	cd /home/dev-user/Projects/Personal/PIC/LibOutputDevices.X && ${MAKE}  -f Makefile CONF=default
	cd /home/dev-user/Projects/Personal/PIC/LibMisc.X && ${MAKE}  -f Makefile CONF=default
	cd /home/dev-user/Projects/Personal/PIC/Lib32Peripherals.X && ${MAKE}  -f Makefile CONF=default


# Subprojects
.clean-subprojects:
	cd /home/dev-user/Projects/Personal/PIC/LibOutputDevices.X && rm -rf "build/default" "dist/default"
	cd /home/dev-user/Projects/Personal/PIC/LibMisc.X && rm -rf "build/default" "dist/default"
	cd /home/dev-user/Projects/Personal/PIC/Lib32Peripherals.X && rm -rf "build/default" "dist/default"

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
