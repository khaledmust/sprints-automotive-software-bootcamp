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
FINAL_IMAGE=${DISTDIR}/avr-drivers.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/avr-drivers.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=ecual/ultrasonic_sensor/ultrasonic_sensor.c ecual/push_button/push_button.c ecual/led/led.c ecual/lcd/lcd.c ecual/keypad/keypad.c ecual/buzzer/buzzer.c mcal/timer/timer.c mcal/spi/spi.c mcal/gpio/gpio.c services/timer_services.c main.c application/application.c mcal/interrupt/exi.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/ecual/ultrasonic_sensor/ultrasonic_sensor.o ${OBJECTDIR}/ecual/push_button/push_button.o ${OBJECTDIR}/ecual/led/led.o ${OBJECTDIR}/ecual/lcd/lcd.o ${OBJECTDIR}/ecual/keypad/keypad.o ${OBJECTDIR}/ecual/buzzer/buzzer.o ${OBJECTDIR}/mcal/timer/timer.o ${OBJECTDIR}/mcal/spi/spi.o ${OBJECTDIR}/mcal/gpio/gpio.o ${OBJECTDIR}/services/timer_services.o ${OBJECTDIR}/main.o ${OBJECTDIR}/application/application.o ${OBJECTDIR}/mcal/interrupt/exi.o
POSSIBLE_DEPFILES=${OBJECTDIR}/ecual/ultrasonic_sensor/ultrasonic_sensor.o.d ${OBJECTDIR}/ecual/push_button/push_button.o.d ${OBJECTDIR}/ecual/led/led.o.d ${OBJECTDIR}/ecual/lcd/lcd.o.d ${OBJECTDIR}/ecual/keypad/keypad.o.d ${OBJECTDIR}/ecual/buzzer/buzzer.o.d ${OBJECTDIR}/mcal/timer/timer.o.d ${OBJECTDIR}/mcal/spi/spi.o.d ${OBJECTDIR}/mcal/gpio/gpio.o.d ${OBJECTDIR}/services/timer_services.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/application/application.o.d ${OBJECTDIR}/mcal/interrupt/exi.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/ecual/ultrasonic_sensor/ultrasonic_sensor.o ${OBJECTDIR}/ecual/push_button/push_button.o ${OBJECTDIR}/ecual/led/led.o ${OBJECTDIR}/ecual/lcd/lcd.o ${OBJECTDIR}/ecual/keypad/keypad.o ${OBJECTDIR}/ecual/buzzer/buzzer.o ${OBJECTDIR}/mcal/timer/timer.o ${OBJECTDIR}/mcal/spi/spi.o ${OBJECTDIR}/mcal/gpio/gpio.o ${OBJECTDIR}/services/timer_services.o ${OBJECTDIR}/main.o ${OBJECTDIR}/application/application.o ${OBJECTDIR}/mcal/interrupt/exi.o

# Source Files
SOURCEFILES=ecual/ultrasonic_sensor/ultrasonic_sensor.c ecual/push_button/push_button.c ecual/led/led.c ecual/lcd/lcd.c ecual/keypad/keypad.c ecual/buzzer/buzzer.c mcal/timer/timer.c mcal/spi/spi.c mcal/gpio/gpio.c services/timer_services.c main.c application/application.c mcal/interrupt/exi.c

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

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/avr-drivers.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

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
${OBJECTDIR}/ecual/ultrasonic_sensor/ultrasonic_sensor.o: ecual/ultrasonic_sensor/ultrasonic_sensor.c  .generated_files/flags/default/75320577e81d1be033a3def91d352485a91cd01d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ecual/ultrasonic_sensor" 
	@${RM} ${OBJECTDIR}/ecual/ultrasonic_sensor/ultrasonic_sensor.o.d 
	@${RM} ${OBJECTDIR}/ecual/ultrasonic_sensor/ultrasonic_sensor.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/ecual/ultrasonic_sensor/ultrasonic_sensor.o.d" -MT "${OBJECTDIR}/ecual/ultrasonic_sensor/ultrasonic_sensor.o.d" -MT ${OBJECTDIR}/ecual/ultrasonic_sensor/ultrasonic_sensor.o  -o ${OBJECTDIR}/ecual/ultrasonic_sensor/ultrasonic_sensor.o ecual/ultrasonic_sensor/ultrasonic_sensor.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/ecual/push_button/push_button.o: ecual/push_button/push_button.c  .generated_files/flags/default/c2bbbf746b276121886192566b6c5164f69c0ff5 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ecual/push_button" 
	@${RM} ${OBJECTDIR}/ecual/push_button/push_button.o.d 
	@${RM} ${OBJECTDIR}/ecual/push_button/push_button.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/ecual/push_button/push_button.o.d" -MT "${OBJECTDIR}/ecual/push_button/push_button.o.d" -MT ${OBJECTDIR}/ecual/push_button/push_button.o  -o ${OBJECTDIR}/ecual/push_button/push_button.o ecual/push_button/push_button.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/ecual/led/led.o: ecual/led/led.c  .generated_files/flags/default/14699e95511591e2063df789aefb446e0dd9ea6e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ecual/led" 
	@${RM} ${OBJECTDIR}/ecual/led/led.o.d 
	@${RM} ${OBJECTDIR}/ecual/led/led.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/ecual/led/led.o.d" -MT "${OBJECTDIR}/ecual/led/led.o.d" -MT ${OBJECTDIR}/ecual/led/led.o  -o ${OBJECTDIR}/ecual/led/led.o ecual/led/led.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/ecual/lcd/lcd.o: ecual/lcd/lcd.c  .generated_files/flags/default/85e949f9aae3b76ecfbd0aacc86afe76842e792d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ecual/lcd" 
	@${RM} ${OBJECTDIR}/ecual/lcd/lcd.o.d 
	@${RM} ${OBJECTDIR}/ecual/lcd/lcd.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/ecual/lcd/lcd.o.d" -MT "${OBJECTDIR}/ecual/lcd/lcd.o.d" -MT ${OBJECTDIR}/ecual/lcd/lcd.o  -o ${OBJECTDIR}/ecual/lcd/lcd.o ecual/lcd/lcd.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/ecual/keypad/keypad.o: ecual/keypad/keypad.c  .generated_files/flags/default/652230bf6740479d2d028f1902f9d6128b095ade .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ecual/keypad" 
	@${RM} ${OBJECTDIR}/ecual/keypad/keypad.o.d 
	@${RM} ${OBJECTDIR}/ecual/keypad/keypad.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/ecual/keypad/keypad.o.d" -MT "${OBJECTDIR}/ecual/keypad/keypad.o.d" -MT ${OBJECTDIR}/ecual/keypad/keypad.o  -o ${OBJECTDIR}/ecual/keypad/keypad.o ecual/keypad/keypad.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/ecual/buzzer/buzzer.o: ecual/buzzer/buzzer.c  .generated_files/flags/default/4425b62de5c6d7489bc4e8b377fa59c18eac4e41 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ecual/buzzer" 
	@${RM} ${OBJECTDIR}/ecual/buzzer/buzzer.o.d 
	@${RM} ${OBJECTDIR}/ecual/buzzer/buzzer.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/ecual/buzzer/buzzer.o.d" -MT "${OBJECTDIR}/ecual/buzzer/buzzer.o.d" -MT ${OBJECTDIR}/ecual/buzzer/buzzer.o  -o ${OBJECTDIR}/ecual/buzzer/buzzer.o ecual/buzzer/buzzer.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/mcal/timer/timer.o: mcal/timer/timer.c  .generated_files/flags/default/5236d94709822a8ccc87dd3484e9f90c36a4dc5b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcal/timer" 
	@${RM} ${OBJECTDIR}/mcal/timer/timer.o.d 
	@${RM} ${OBJECTDIR}/mcal/timer/timer.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/mcal/timer/timer.o.d" -MT "${OBJECTDIR}/mcal/timer/timer.o.d" -MT ${OBJECTDIR}/mcal/timer/timer.o  -o ${OBJECTDIR}/mcal/timer/timer.o mcal/timer/timer.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/mcal/spi/spi.o: mcal/spi/spi.c  .generated_files/flags/default/66a3661453ea03eac2e5b970d81bfef601712775 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcal/spi" 
	@${RM} ${OBJECTDIR}/mcal/spi/spi.o.d 
	@${RM} ${OBJECTDIR}/mcal/spi/spi.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/mcal/spi/spi.o.d" -MT "${OBJECTDIR}/mcal/spi/spi.o.d" -MT ${OBJECTDIR}/mcal/spi/spi.o  -o ${OBJECTDIR}/mcal/spi/spi.o mcal/spi/spi.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/mcal/gpio/gpio.o: mcal/gpio/gpio.c  .generated_files/flags/default/1dc6713ccfd60b3b6c5514c5557dd2788b8c0132 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcal/gpio" 
	@${RM} ${OBJECTDIR}/mcal/gpio/gpio.o.d 
	@${RM} ${OBJECTDIR}/mcal/gpio/gpio.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/mcal/gpio/gpio.o.d" -MT "${OBJECTDIR}/mcal/gpio/gpio.o.d" -MT ${OBJECTDIR}/mcal/gpio/gpio.o  -o ${OBJECTDIR}/mcal/gpio/gpio.o mcal/gpio/gpio.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/services/timer_services.o: services/timer_services.c  .generated_files/flags/default/9a5471efa05fb22dec56ca386c03df7d3959214d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/services" 
	@${RM} ${OBJECTDIR}/services/timer_services.o.d 
	@${RM} ${OBJECTDIR}/services/timer_services.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/services/timer_services.o.d" -MT "${OBJECTDIR}/services/timer_services.o.d" -MT ${OBJECTDIR}/services/timer_services.o  -o ${OBJECTDIR}/services/timer_services.o services/timer_services.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/ac19577f2f7952278de723de039de3bbf6f2c8 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/main.o.d" -MT "${OBJECTDIR}/main.o.d" -MT ${OBJECTDIR}/main.o  -o ${OBJECTDIR}/main.o main.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/application/application.o: application/application.c  .generated_files/flags/default/e87eee8abd1e61793acba572d02a9cdc9678e2d4 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/application" 
	@${RM} ${OBJECTDIR}/application/application.o.d 
	@${RM} ${OBJECTDIR}/application/application.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/application/application.o.d" -MT "${OBJECTDIR}/application/application.o.d" -MT ${OBJECTDIR}/application/application.o  -o ${OBJECTDIR}/application/application.o application/application.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/mcal/interrupt/exi.o: mcal/interrupt/exi.c  .generated_files/flags/default/9380c256e79b42d1ece5ad5125228055ced524d4 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcal/interrupt" 
	@${RM} ${OBJECTDIR}/mcal/interrupt/exi.o.d 
	@${RM} ${OBJECTDIR}/mcal/interrupt/exi.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/mcal/interrupt/exi.o.d" -MT "${OBJECTDIR}/mcal/interrupt/exi.o.d" -MT ${OBJECTDIR}/mcal/interrupt/exi.o  -o ${OBJECTDIR}/mcal/interrupt/exi.o mcal/interrupt/exi.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
else
${OBJECTDIR}/ecual/ultrasonic_sensor/ultrasonic_sensor.o: ecual/ultrasonic_sensor/ultrasonic_sensor.c  .generated_files/flags/default/a41b30fe39b74746e919f7f1181b0b6bbf07ead5 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ecual/ultrasonic_sensor" 
	@${RM} ${OBJECTDIR}/ecual/ultrasonic_sensor/ultrasonic_sensor.o.d 
	@${RM} ${OBJECTDIR}/ecual/ultrasonic_sensor/ultrasonic_sensor.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/ecual/ultrasonic_sensor/ultrasonic_sensor.o.d" -MT "${OBJECTDIR}/ecual/ultrasonic_sensor/ultrasonic_sensor.o.d" -MT ${OBJECTDIR}/ecual/ultrasonic_sensor/ultrasonic_sensor.o  -o ${OBJECTDIR}/ecual/ultrasonic_sensor/ultrasonic_sensor.o ecual/ultrasonic_sensor/ultrasonic_sensor.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/ecual/push_button/push_button.o: ecual/push_button/push_button.c  .generated_files/flags/default/d71878f27b55562bf969295f3ff5085884d88427 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ecual/push_button" 
	@${RM} ${OBJECTDIR}/ecual/push_button/push_button.o.d 
	@${RM} ${OBJECTDIR}/ecual/push_button/push_button.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/ecual/push_button/push_button.o.d" -MT "${OBJECTDIR}/ecual/push_button/push_button.o.d" -MT ${OBJECTDIR}/ecual/push_button/push_button.o  -o ${OBJECTDIR}/ecual/push_button/push_button.o ecual/push_button/push_button.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/ecual/led/led.o: ecual/led/led.c  .generated_files/flags/default/b46c2575202a31b4f4b01c7745857682e174e803 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ecual/led" 
	@${RM} ${OBJECTDIR}/ecual/led/led.o.d 
	@${RM} ${OBJECTDIR}/ecual/led/led.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/ecual/led/led.o.d" -MT "${OBJECTDIR}/ecual/led/led.o.d" -MT ${OBJECTDIR}/ecual/led/led.o  -o ${OBJECTDIR}/ecual/led/led.o ecual/led/led.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/ecual/lcd/lcd.o: ecual/lcd/lcd.c  .generated_files/flags/default/56adf43b8d066e8425ba068fc40157432bf036d9 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ecual/lcd" 
	@${RM} ${OBJECTDIR}/ecual/lcd/lcd.o.d 
	@${RM} ${OBJECTDIR}/ecual/lcd/lcd.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/ecual/lcd/lcd.o.d" -MT "${OBJECTDIR}/ecual/lcd/lcd.o.d" -MT ${OBJECTDIR}/ecual/lcd/lcd.o  -o ${OBJECTDIR}/ecual/lcd/lcd.o ecual/lcd/lcd.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/ecual/keypad/keypad.o: ecual/keypad/keypad.c  .generated_files/flags/default/859723882400adab677b4f7832c8bdd3247d86e1 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ecual/keypad" 
	@${RM} ${OBJECTDIR}/ecual/keypad/keypad.o.d 
	@${RM} ${OBJECTDIR}/ecual/keypad/keypad.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/ecual/keypad/keypad.o.d" -MT "${OBJECTDIR}/ecual/keypad/keypad.o.d" -MT ${OBJECTDIR}/ecual/keypad/keypad.o  -o ${OBJECTDIR}/ecual/keypad/keypad.o ecual/keypad/keypad.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/ecual/buzzer/buzzer.o: ecual/buzzer/buzzer.c  .generated_files/flags/default/788aa6eb77e056369c1445384ee84fc2b57ae6e3 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ecual/buzzer" 
	@${RM} ${OBJECTDIR}/ecual/buzzer/buzzer.o.d 
	@${RM} ${OBJECTDIR}/ecual/buzzer/buzzer.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/ecual/buzzer/buzzer.o.d" -MT "${OBJECTDIR}/ecual/buzzer/buzzer.o.d" -MT ${OBJECTDIR}/ecual/buzzer/buzzer.o  -o ${OBJECTDIR}/ecual/buzzer/buzzer.o ecual/buzzer/buzzer.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/mcal/timer/timer.o: mcal/timer/timer.c  .generated_files/flags/default/78411a52da40f0dc841b44adcdc166612406bd12 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcal/timer" 
	@${RM} ${OBJECTDIR}/mcal/timer/timer.o.d 
	@${RM} ${OBJECTDIR}/mcal/timer/timer.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/mcal/timer/timer.o.d" -MT "${OBJECTDIR}/mcal/timer/timer.o.d" -MT ${OBJECTDIR}/mcal/timer/timer.o  -o ${OBJECTDIR}/mcal/timer/timer.o mcal/timer/timer.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/mcal/spi/spi.o: mcal/spi/spi.c  .generated_files/flags/default/7888b28b5fdaab2b7d4b8421b43b82cdf1e44e1c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcal/spi" 
	@${RM} ${OBJECTDIR}/mcal/spi/spi.o.d 
	@${RM} ${OBJECTDIR}/mcal/spi/spi.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/mcal/spi/spi.o.d" -MT "${OBJECTDIR}/mcal/spi/spi.o.d" -MT ${OBJECTDIR}/mcal/spi/spi.o  -o ${OBJECTDIR}/mcal/spi/spi.o mcal/spi/spi.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/mcal/gpio/gpio.o: mcal/gpio/gpio.c  .generated_files/flags/default/3c2038210481684ded296c3efa65d2a8aee9bff6 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcal/gpio" 
	@${RM} ${OBJECTDIR}/mcal/gpio/gpio.o.d 
	@${RM} ${OBJECTDIR}/mcal/gpio/gpio.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/mcal/gpio/gpio.o.d" -MT "${OBJECTDIR}/mcal/gpio/gpio.o.d" -MT ${OBJECTDIR}/mcal/gpio/gpio.o  -o ${OBJECTDIR}/mcal/gpio/gpio.o mcal/gpio/gpio.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/services/timer_services.o: services/timer_services.c  .generated_files/flags/default/3566bb0e0499c6f3e176e1fe905ee92ffcff0e1a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/services" 
	@${RM} ${OBJECTDIR}/services/timer_services.o.d 
	@${RM} ${OBJECTDIR}/services/timer_services.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/services/timer_services.o.d" -MT "${OBJECTDIR}/services/timer_services.o.d" -MT ${OBJECTDIR}/services/timer_services.o  -o ${OBJECTDIR}/services/timer_services.o services/timer_services.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/41ad51fbf4f195a16c7f678833aab65042031721 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/main.o.d" -MT "${OBJECTDIR}/main.o.d" -MT ${OBJECTDIR}/main.o  -o ${OBJECTDIR}/main.o main.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/application/application.o: application/application.c  .generated_files/flags/default/958c388405eb38c2e5742f208a1f7d71f24c8ea8 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/application" 
	@${RM} ${OBJECTDIR}/application/application.o.d 
	@${RM} ${OBJECTDIR}/application/application.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/application/application.o.d" -MT "${OBJECTDIR}/application/application.o.d" -MT ${OBJECTDIR}/application/application.o  -o ${OBJECTDIR}/application/application.o application/application.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/mcal/interrupt/exi.o: mcal/interrupt/exi.c  .generated_files/flags/default/ef95da78d597530c0bf10d8dd988c43132a1acd4 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcal/interrupt" 
	@${RM} ${OBJECTDIR}/mcal/interrupt/exi.o.d 
	@${RM} ${OBJECTDIR}/mcal/interrupt/exi.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/mcal/interrupt/exi.o.d" -MT "${OBJECTDIR}/mcal/interrupt/exi.o.d" -MT ${OBJECTDIR}/mcal/interrupt/exi.o  -o ${OBJECTDIR}/mcal/interrupt/exi.o mcal/interrupt/exi.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/avr-drivers.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mmcu=atmega32 ${PACK_COMMON_OPTIONS}  -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2 -D__$(MP_PROCESSOR_OPTION)__  -Wl,-Map="${DISTDIR}/avr-drivers.X.${IMAGE_TYPE}.map"    -o ${DISTDIR}/avr-drivers.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}      -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_SIMULATOR=1 -Wl,--gc-sections -Wl,--start-group  -Wl,-lm -Wl,--end-group 
	
	
	
	
	
	
else
${DISTDIR}/avr-drivers.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mmcu=atmega32 ${PACK_COMMON_OPTIONS}  -D__$(MP_PROCESSOR_OPTION)__  -Wl,-Map="${DISTDIR}/avr-drivers.X.${IMAGE_TYPE}.map"    -o ${DISTDIR}/avr-drivers.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}      -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION) -Wl,--gc-sections -Wl,--start-group  -Wl,-lm -Wl,--end-group 
	${MP_CC_DIR}/avr-objcopy -O ihex "${DISTDIR}/avr-drivers.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}" "${DISTDIR}/avr-drivers.X.${IMAGE_TYPE}.hex"
	
	
	
	
	
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
