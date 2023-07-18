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
ifeq "$(wildcard nbproject/Makefile-local-USBASP.mk)" "nbproject/Makefile-local-USBASP.mk"
include nbproject/Makefile-local-USBASP.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=USBASP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/blinky_3v0.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/blinky_3v0.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=ecual/push_button/push_button.c ecual/led/led.c mcal/timer/timer.c mcal/gpio/gpio.c services/timer_services.c application/application.c mcal/interrupt/exi.c main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/ecual/push_button/push_button.o ${OBJECTDIR}/ecual/led/led.o ${OBJECTDIR}/mcal/timer/timer.o ${OBJECTDIR}/mcal/gpio/gpio.o ${OBJECTDIR}/services/timer_services.o ${OBJECTDIR}/application/application.o ${OBJECTDIR}/mcal/interrupt/exi.o ${OBJECTDIR}/main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/ecual/push_button/push_button.o.d ${OBJECTDIR}/ecual/led/led.o.d ${OBJECTDIR}/mcal/timer/timer.o.d ${OBJECTDIR}/mcal/gpio/gpio.o.d ${OBJECTDIR}/services/timer_services.o.d ${OBJECTDIR}/application/application.o.d ${OBJECTDIR}/mcal/interrupt/exi.o.d ${OBJECTDIR}/main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/ecual/push_button/push_button.o ${OBJECTDIR}/ecual/led/led.o ${OBJECTDIR}/mcal/timer/timer.o ${OBJECTDIR}/mcal/gpio/gpio.o ${OBJECTDIR}/services/timer_services.o ${OBJECTDIR}/application/application.o ${OBJECTDIR}/mcal/interrupt/exi.o ${OBJECTDIR}/main.o

# Source Files
SOURCEFILES=ecual/push_button/push_button.c ecual/led/led.c mcal/timer/timer.c mcal/gpio/gpio.c services/timer_services.c application/application.c mcal/interrupt/exi.c main.c

# Pack Options 
PACK_COMPILER_OPTIONS=-I "${DFP_DIR}/include"
PACK_COMMON_OPTIONS=-B "${DFP_DIR}/gcc/dev/atmega32"



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

# The following macros may be used in the pre and post step lines
_/_=/
ShExtension=.sh
Device=ATmega32
ProjectDir=/home/khaled/projects/blinky_v3_0/blinky_3v0.X
ProjectName=blinky_3v0
ConfName=USBASP
ImagePath=dist/USBASP/${IMAGE_TYPE}/blinky_3v0.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
ImageDir=dist/USBASP/${IMAGE_TYPE}
ImageName=blinky_3v0.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IsDebug="true"
else
IsDebug="false"
endif

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-USBASP.mk ${DISTDIR}/blinky_3v0.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
	@echo "--------------------------------------"
	@echo "User defined post-build step: [avrdude -c usbasp -p m32 -U flash:w:${ProjectDir}/${ImagePath}]"
	@avrdude -c usbasp -p m32 -U flash:w:${ProjectDir}/${ImagePath}
	@echo "--------------------------------------"

MP_PROCESSOR_OPTION=ATmega32
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
${OBJECTDIR}/ecual/push_button/push_button.o: ecual/push_button/push_button.c  .generated_files/flags/USBASP/c4280c724123f67e169ec2423704b28b041db65f .generated_files/flags/USBASP/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ecual/push_button" 
	@${RM} ${OBJECTDIR}/ecual/push_button/push_button.o.d 
	@${RM} ${OBJECTDIR}/ecual/push_button/push_button.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/ecual/push_button/push_button.o.d" -MT "${OBJECTDIR}/ecual/push_button/push_button.o.d" -MT ${OBJECTDIR}/ecual/push_button/push_button.o  -o ${OBJECTDIR}/ecual/push_button/push_button.o ecual/push_button/push_button.c  -DXPRJ_USBASP=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/ecual/led/led.o: ecual/led/led.c  .generated_files/flags/USBASP/39bdf72c0b1e5da65634b021ea69054b90047ff7 .generated_files/flags/USBASP/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ecual/led" 
	@${RM} ${OBJECTDIR}/ecual/led/led.o.d 
	@${RM} ${OBJECTDIR}/ecual/led/led.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/ecual/led/led.o.d" -MT "${OBJECTDIR}/ecual/led/led.o.d" -MT ${OBJECTDIR}/ecual/led/led.o  -o ${OBJECTDIR}/ecual/led/led.o ecual/led/led.c  -DXPRJ_USBASP=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/mcal/timer/timer.o: mcal/timer/timer.c  .generated_files/flags/USBASP/1b4e7922fe46e5f5bc5d0cb8da4506345f6a5cee .generated_files/flags/USBASP/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcal/timer" 
	@${RM} ${OBJECTDIR}/mcal/timer/timer.o.d 
	@${RM} ${OBJECTDIR}/mcal/timer/timer.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/mcal/timer/timer.o.d" -MT "${OBJECTDIR}/mcal/timer/timer.o.d" -MT ${OBJECTDIR}/mcal/timer/timer.o  -o ${OBJECTDIR}/mcal/timer/timer.o mcal/timer/timer.c  -DXPRJ_USBASP=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/mcal/gpio/gpio.o: mcal/gpio/gpio.c  .generated_files/flags/USBASP/d185009b803ef3cb8eabd2e35abcfcd1c5e8873c .generated_files/flags/USBASP/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcal/gpio" 
	@${RM} ${OBJECTDIR}/mcal/gpio/gpio.o.d 
	@${RM} ${OBJECTDIR}/mcal/gpio/gpio.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/mcal/gpio/gpio.o.d" -MT "${OBJECTDIR}/mcal/gpio/gpio.o.d" -MT ${OBJECTDIR}/mcal/gpio/gpio.o  -o ${OBJECTDIR}/mcal/gpio/gpio.o mcal/gpio/gpio.c  -DXPRJ_USBASP=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/services/timer_services.o: services/timer_services.c  .generated_files/flags/USBASP/bf55b65ef9ceb70387fdf5302b6ce8b02a587b58 .generated_files/flags/USBASP/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/services" 
	@${RM} ${OBJECTDIR}/services/timer_services.o.d 
	@${RM} ${OBJECTDIR}/services/timer_services.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/services/timer_services.o.d" -MT "${OBJECTDIR}/services/timer_services.o.d" -MT ${OBJECTDIR}/services/timer_services.o  -o ${OBJECTDIR}/services/timer_services.o services/timer_services.c  -DXPRJ_USBASP=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/application/application.o: application/application.c  .generated_files/flags/USBASP/a2e7fa43dc8c1bc868933d45aa6f93b15f2e26f0 .generated_files/flags/USBASP/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/application" 
	@${RM} ${OBJECTDIR}/application/application.o.d 
	@${RM} ${OBJECTDIR}/application/application.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/application/application.o.d" -MT "${OBJECTDIR}/application/application.o.d" -MT ${OBJECTDIR}/application/application.o  -o ${OBJECTDIR}/application/application.o application/application.c  -DXPRJ_USBASP=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/mcal/interrupt/exi.o: mcal/interrupt/exi.c  .generated_files/flags/USBASP/1d3ccb28873ac5339fa8375c52983f60105d9bd2 .generated_files/flags/USBASP/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcal/interrupt" 
	@${RM} ${OBJECTDIR}/mcal/interrupt/exi.o.d 
	@${RM} ${OBJECTDIR}/mcal/interrupt/exi.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/mcal/interrupt/exi.o.d" -MT "${OBJECTDIR}/mcal/interrupt/exi.o.d" -MT ${OBJECTDIR}/mcal/interrupt/exi.o  -o ${OBJECTDIR}/mcal/interrupt/exi.o mcal/interrupt/exi.c  -DXPRJ_USBASP=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/USBASP/f92f4a1f9986f3fa30512b5dac33859702371d32 .generated_files/flags/USBASP/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/main.o.d" -MT "${OBJECTDIR}/main.o.d" -MT ${OBJECTDIR}/main.o  -o ${OBJECTDIR}/main.o main.c  -DXPRJ_USBASP=$(CND_CONF)  $(COMPARISON_BUILD) 
	
else
${OBJECTDIR}/ecual/push_button/push_button.o: ecual/push_button/push_button.c  .generated_files/flags/USBASP/23a752ebc2df43b1d1a4ad67c8eb6281b70eeb76 .generated_files/flags/USBASP/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ecual/push_button" 
	@${RM} ${OBJECTDIR}/ecual/push_button/push_button.o.d 
	@${RM} ${OBJECTDIR}/ecual/push_button/push_button.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/ecual/push_button/push_button.o.d" -MT "${OBJECTDIR}/ecual/push_button/push_button.o.d" -MT ${OBJECTDIR}/ecual/push_button/push_button.o  -o ${OBJECTDIR}/ecual/push_button/push_button.o ecual/push_button/push_button.c  -DXPRJ_USBASP=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/ecual/led/led.o: ecual/led/led.c  .generated_files/flags/USBASP/b4991024137ad893c6bb79f151f6921a2b0e238b .generated_files/flags/USBASP/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ecual/led" 
	@${RM} ${OBJECTDIR}/ecual/led/led.o.d 
	@${RM} ${OBJECTDIR}/ecual/led/led.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/ecual/led/led.o.d" -MT "${OBJECTDIR}/ecual/led/led.o.d" -MT ${OBJECTDIR}/ecual/led/led.o  -o ${OBJECTDIR}/ecual/led/led.o ecual/led/led.c  -DXPRJ_USBASP=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/mcal/timer/timer.o: mcal/timer/timer.c  .generated_files/flags/USBASP/ef48ff938de7b0487c602bdc88f73bf54e3b9a70 .generated_files/flags/USBASP/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcal/timer" 
	@${RM} ${OBJECTDIR}/mcal/timer/timer.o.d 
	@${RM} ${OBJECTDIR}/mcal/timer/timer.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/mcal/timer/timer.o.d" -MT "${OBJECTDIR}/mcal/timer/timer.o.d" -MT ${OBJECTDIR}/mcal/timer/timer.o  -o ${OBJECTDIR}/mcal/timer/timer.o mcal/timer/timer.c  -DXPRJ_USBASP=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/mcal/gpio/gpio.o: mcal/gpio/gpio.c  .generated_files/flags/USBASP/74f6579e04a8effe215dabeb425d523f9ae443c2 .generated_files/flags/USBASP/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcal/gpio" 
	@${RM} ${OBJECTDIR}/mcal/gpio/gpio.o.d 
	@${RM} ${OBJECTDIR}/mcal/gpio/gpio.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/mcal/gpio/gpio.o.d" -MT "${OBJECTDIR}/mcal/gpio/gpio.o.d" -MT ${OBJECTDIR}/mcal/gpio/gpio.o  -o ${OBJECTDIR}/mcal/gpio/gpio.o mcal/gpio/gpio.c  -DXPRJ_USBASP=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/services/timer_services.o: services/timer_services.c  .generated_files/flags/USBASP/8fa4412863dc37682477998d819ae8937136ff1b .generated_files/flags/USBASP/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/services" 
	@${RM} ${OBJECTDIR}/services/timer_services.o.d 
	@${RM} ${OBJECTDIR}/services/timer_services.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/services/timer_services.o.d" -MT "${OBJECTDIR}/services/timer_services.o.d" -MT ${OBJECTDIR}/services/timer_services.o  -o ${OBJECTDIR}/services/timer_services.o services/timer_services.c  -DXPRJ_USBASP=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/application/application.o: application/application.c  .generated_files/flags/USBASP/bf1cd9cea73afaa98f9f0b68d108e851913b3c56 .generated_files/flags/USBASP/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/application" 
	@${RM} ${OBJECTDIR}/application/application.o.d 
	@${RM} ${OBJECTDIR}/application/application.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/application/application.o.d" -MT "${OBJECTDIR}/application/application.o.d" -MT ${OBJECTDIR}/application/application.o  -o ${OBJECTDIR}/application/application.o application/application.c  -DXPRJ_USBASP=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/mcal/interrupt/exi.o: mcal/interrupt/exi.c  .generated_files/flags/USBASP/534fc5255d165c88a64fb23b7603d6aeda58a2aa .generated_files/flags/USBASP/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcal/interrupt" 
	@${RM} ${OBJECTDIR}/mcal/interrupt/exi.o.d 
	@${RM} ${OBJECTDIR}/mcal/interrupt/exi.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/mcal/interrupt/exi.o.d" -MT "${OBJECTDIR}/mcal/interrupt/exi.o.d" -MT ${OBJECTDIR}/mcal/interrupt/exi.o  -o ${OBJECTDIR}/mcal/interrupt/exi.o mcal/interrupt/exi.c  -DXPRJ_USBASP=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/USBASP/a8808570e9a43d9b169cf90c08abc98955f88f8b .generated_files/flags/USBASP/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/main.o.d" -MT "${OBJECTDIR}/main.o.d" -MT ${OBJECTDIR}/main.o  -o ${OBJECTDIR}/main.o main.c  -DXPRJ_USBASP=$(CND_CONF)  $(COMPARISON_BUILD) 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/blinky_3v0.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mmcu=atmega32 ${PACK_COMMON_OPTIONS}  -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2 -D__$(MP_PROCESSOR_OPTION)__  -Wl,-Map="${DISTDIR}/blinky_3v0.X.${IMAGE_TYPE}.map"    -o ${DISTDIR}/blinky_3v0.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}      -DXPRJ_USBASP=$(CND_CONF)  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_SIMULATOR=1 -Wl,--gc-sections -Wl,--start-group  -Wl,-lm -Wl,--end-group 
	
	
	
	
	
	
else
${DISTDIR}/blinky_3v0.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mmcu=atmega32 ${PACK_COMMON_OPTIONS}  -D__$(MP_PROCESSOR_OPTION)__  -Wl,-Map="${DISTDIR}/blinky_3v0.X.${IMAGE_TYPE}.map"    -o ${DISTDIR}/blinky_3v0.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}      -DXPRJ_USBASP=$(CND_CONF)  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION) -Wl,--gc-sections -Wl,--start-group  -Wl,-lm -Wl,--end-group 
	${MP_CC_DIR}/avr-objcopy -O ihex "${DISTDIR}/blinky_3v0.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}" "${DISTDIR}/blinky_3v0.X.${IMAGE_TYPE}.hex"
	
	
	
	
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
