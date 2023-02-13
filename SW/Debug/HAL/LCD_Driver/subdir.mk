################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/LCD_Driver/lcd.c 

OBJS += \
./HAL/LCD_Driver/lcd.o 

C_DEPS += \
./HAL/LCD_Driver/lcd.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/LCD_Driver/%.o: ../HAL/LCD_Driver/%.c HAL/LCD_Driver/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\eclipse work space\EEPROM_Driver\HAL\EEPROM_Driver" -I"D:\eclipse work space\EEPROM_Driver\HAL\Interrupt_HAL" -I"D:\eclipse work space\EEPROM_Driver\HAL\LCD_Driver" -I"D:\eclipse work space\EEPROM_Driver\HAL\Timer_Driver" -I"D:\eclipse work space\EEPROM_Driver\MCAL" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


