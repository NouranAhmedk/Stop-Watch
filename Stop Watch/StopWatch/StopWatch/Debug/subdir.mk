################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ISR.c \
../Interrupt.c \
../Main.c \
../SevenSegmentDisplay.c \
../SevenSegmentTimeCalc.c \
../Timer1_COMP_Init.c 

OBJS += \
./ISR.o \
./Interrupt.o \
./Main.o \
./SevenSegmentDisplay.o \
./SevenSegmentTimeCalc.o \
./Timer1_COMP_Init.o 

C_DEPS += \
./ISR.d \
./Interrupt.d \
./Main.d \
./SevenSegmentDisplay.d \
./SevenSegmentTimeCalc.d \
./Timer1_COMP_Init.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


