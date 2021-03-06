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
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/StepperSystem32_v2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/StepperSystem32_v2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=/home/dev1/Projects/PIC/StepperSystem32_v2.X/interrupts.c /home/dev1/Projects/PIC/StepperSystem32_v2.X/main.c /home/dev1/Projects/PIC/StepperSystem32_v2.X/System.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/850872466/interrupts.o ${OBJECTDIR}/_ext/850872466/main.o ${OBJECTDIR}/_ext/850872466/System.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/850872466/interrupts.o.d ${OBJECTDIR}/_ext/850872466/main.o.d ${OBJECTDIR}/_ext/850872466/System.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/850872466/interrupts.o ${OBJECTDIR}/_ext/850872466/main.o ${OBJECTDIR}/_ext/850872466/System.o

# Source Files
SOURCEFILES=/home/dev1/Projects/PIC/StepperSystem32_v2.X/interrupts.c /home/dev1/Projects/PIC/StepperSystem32_v2.X/main.c /home/dev1/Projects/PIC/StepperSystem32_v2.X/System.c



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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/StepperSystem32_v2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

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
${OBJECTDIR}/_ext/850872466/interrupts.o: /home/dev1/Projects/PIC/StepperSystem32_v2.X/interrupts.c  .generated_files/e1e8086ac93e71b1e01b767bacf36c7def7ebc66.flag .generated_files/71b2fa7f85a22426d8b136d9a94b6b5776fdc3b0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/850872466" 
	@${RM} ${OBJECTDIR}/_ext/850872466/interrupts.o.d 
	@${RM} ${OBJECTDIR}/_ext/850872466/interrupts.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../IncSystemDefs" -I"../Lib32Peripherals.X" -I"../LibOutputDevices.X" -MP -MMD -MF "${OBJECTDIR}/_ext/850872466/interrupts.o.d" -o ${OBJECTDIR}/_ext/850872466/interrupts.o /home/dev1/Projects/PIC/StepperSystem32_v2.X/interrupts.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/850872466/main.o: /home/dev1/Projects/PIC/StepperSystem32_v2.X/main.c  .generated_files/8331047cbbe25c5838b507e6896561049737d6e7.flag .generated_files/71b2fa7f85a22426d8b136d9a94b6b5776fdc3b0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/850872466" 
	@${RM} ${OBJECTDIR}/_ext/850872466/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/850872466/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../IncSystemDefs" -I"../Lib32Peripherals.X" -I"../LibOutputDevices.X" -MP -MMD -MF "${OBJECTDIR}/_ext/850872466/main.o.d" -o ${OBJECTDIR}/_ext/850872466/main.o /home/dev1/Projects/PIC/StepperSystem32_v2.X/main.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/850872466/System.o: /home/dev1/Projects/PIC/StepperSystem32_v2.X/System.c  .generated_files/3748b01dcd8afdc9714c6a5e4009ae055de52d0e.flag .generated_files/71b2fa7f85a22426d8b136d9a94b6b5776fdc3b0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/850872466" 
	@${RM} ${OBJECTDIR}/_ext/850872466/System.o.d 
	@${RM} ${OBJECTDIR}/_ext/850872466/System.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../IncSystemDefs" -I"../Lib32Peripherals.X" -I"../LibOutputDevices.X" -MP -MMD -MF "${OBJECTDIR}/_ext/850872466/System.o.d" -o ${OBJECTDIR}/_ext/850872466/System.o /home/dev1/Projects/PIC/StepperSystem32_v2.X/System.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
else
${OBJECTDIR}/_ext/850872466/interrupts.o: /home/dev1/Projects/PIC/StepperSystem32_v2.X/interrupts.c  .generated_files/fc3b741610ec3c0c6c12ec9b989b456672815150.flag .generated_files/71b2fa7f85a22426d8b136d9a94b6b5776fdc3b0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/850872466" 
	@${RM} ${OBJECTDIR}/_ext/850872466/interrupts.o.d 
	@${RM} ${OBJECTDIR}/_ext/850872466/interrupts.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../IncSystemDefs" -I"../Lib32Peripherals.X" -I"../LibOutputDevices.X" -MP -MMD -MF "${OBJECTDIR}/_ext/850872466/interrupts.o.d" -o ${OBJECTDIR}/_ext/850872466/interrupts.o /home/dev1/Projects/PIC/StepperSystem32_v2.X/interrupts.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/850872466/main.o: /home/dev1/Projects/PIC/StepperSystem32_v2.X/main.c  .generated_files/1ff26a7dc6c845af47e7548ebc603b0d667208aa.flag .generated_files/71b2fa7f85a22426d8b136d9a94b6b5776fdc3b0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/850872466" 
	@${RM} ${OBJECTDIR}/_ext/850872466/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/850872466/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../IncSystemDefs" -I"../Lib32Peripherals.X" -I"../LibOutputDevices.X" -MP -MMD -MF "${OBJECTDIR}/_ext/850872466/main.o.d" -o ${OBJECTDIR}/_ext/850872466/main.o /home/dev1/Projects/PIC/StepperSystem32_v2.X/main.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/850872466/System.o: /home/dev1/Projects/PIC/StepperSystem32_v2.X/System.c  .generated_files/4dca79726a0ccbeaf573f2e2aa1a9b6cb17e9d6a.flag .generated_files/71b2fa7f85a22426d8b136d9a94b6b5776fdc3b0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/850872466" 
	@${RM} ${OBJECTDIR}/_ext/850872466/System.o.d 
	@${RM} ${OBJECTDIR}/_ext/850872466/System.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../IncSystemDefs" -I"../Lib32Peripherals.X" -I"../LibOutputDevices.X" -MP -MMD -MF "${OBJECTDIR}/_ext/850872466/System.o.d" -o ${OBJECTDIR}/_ext/850872466/System.o /home/dev1/Projects/PIC/StepperSystem32_v2.X/System.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/StepperSystem32_v2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  ../LibOutputDevices.X/dist/default/debug/LibOutputDevices.X.a ../LibMisc.X/dist/default/debug/LibMisc.X.a ../Lib32Peripherals.X/dist/default/debug/Lib32Peripherals.X.a ../LibSystemDefs.X/dist/default/production/LibSystemDefs.X.a  
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g   -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/StepperSystem32_v2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    ../LibOutputDevices.X/dist/default/debug/LibOutputDevices.X.a ../LibMisc.X/dist/default/debug/LibMisc.X.a ../Lib32Peripherals.X/dist/default/debug/Lib32Peripherals.X.a ../LibSystemDefs.X/dist/default/production/LibSystemDefs.X.a      -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)      -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -mdfp="${DFP_DIR}"
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/StepperSystem32_v2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  ../LibOutputDevices.X/dist/default/production/LibOutputDevices.X.a ../LibMisc.X/dist/default/production/LibMisc.X.a ../Lib32Peripherals.X/dist/default/production/Lib32Peripherals.X.a ../LibSystemDefs.X/dist/default/production/LibSystemDefs.X.a 
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/StepperSystem32_v2.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    ../LibOutputDevices.X/dist/default/production/LibOutputDevices.X.a ../LibMisc.X/dist/default/production/LibMisc.X.a ../Lib32Peripherals.X/dist/default/production/Lib32Peripherals.X.a ../LibSystemDefs.X/dist/default/production/LibSystemDefs.X.a      -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -mdfp="${DFP_DIR}"
	${MP_CC_DIR}/xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/StepperSystem32_v2.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:
	cd ../LibOutputDevices.X && ${MAKE}  -f Makefile CONF=default
	cd ../LibMisc.X && ${MAKE}  -f Makefile CONF=default
	cd ../Lib32Peripherals.X && ${MAKE}  -f Makefile CONF=default


# Subprojects
.clean-subprojects:
	cd ../LibOutputDevices.X && rm -rf "build/default" "dist/default"
	cd ../LibMisc.X && rm -rf "build/default" "dist/default"
	cd ../Lib32Peripherals.X && rm -rf "build/default" "dist/default"

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
