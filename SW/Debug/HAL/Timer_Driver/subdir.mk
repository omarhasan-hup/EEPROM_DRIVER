################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Timer_Driver/timer0.c 

OBJS += \
./HAL/Timer_Driver/timer0.o 

C_DEPS += \
./HAL/Timer_Driver/timer0.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/Timer_Driver/%.o: ../HAL/Timer_Driver/%.c HAL/Timer_Driver/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\eclipse work space\EEPROM_Driver\HAL\EEPROM_Driver" -I"D:\eclipse work space\EEPROM_Driver\HAL\Interrupt_HAL" -I"D:\eclipse work space\EEPROM_Driver\HAL\LCD_Driver" -I"D:\eclipse work space\EEPROM_Driver\HAL\Timer_Driver" -I"D:\eclipse work space\EEPROM_Driver\MCAL" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


