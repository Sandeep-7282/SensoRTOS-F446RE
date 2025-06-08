################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Drivers/delay.c \
../Core/Src/Drivers/dht11.c \
../Core/Src/Drivers/font5x7.c \
../Core/Src/Drivers/gpio.c \
../Core/Src/Drivers/hcsr04.c \
../Core/Src/Drivers/hcsr501.c \
../Core/Src/Drivers/i2c.c \
../Core/Src/Drivers/ssd1306.c \
../Core/Src/Drivers/uart.c \
../Core/Src/Drivers/uart_cli.c 

OBJS += \
./Core/Src/Drivers/delay.o \
./Core/Src/Drivers/dht11.o \
./Core/Src/Drivers/font5x7.o \
./Core/Src/Drivers/gpio.o \
./Core/Src/Drivers/hcsr04.o \
./Core/Src/Drivers/hcsr501.o \
./Core/Src/Drivers/i2c.o \
./Core/Src/Drivers/ssd1306.o \
./Core/Src/Drivers/uart.o \
./Core/Src/Drivers/uart_cli.o 

C_DEPS += \
./Core/Src/Drivers/delay.d \
./Core/Src/Drivers/dht11.d \
./Core/Src/Drivers/font5x7.d \
./Core/Src/Drivers/gpio.d \
./Core/Src/Drivers/hcsr04.d \
./Core/Src/Drivers/hcsr501.d \
./Core/Src/Drivers/i2c.d \
./Core/Src/Drivers/ssd1306.d \
./Core/Src/Drivers/uart.d \
./Core/Src/Drivers/uart_cli.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Drivers/%.o Core/Src/Drivers/%.su Core/Src/Drivers/%.cyclo: ../Core/Src/Drivers/%.c Core/Src/Drivers/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"D:/Firmware/STM32/FreeRTOS_Concepts/SensoRTOS_F446RE/SensoRTOS_F446RE/Core/Inc/Drivers" -I"D:/Firmware/STM32/FreeRTOS_Concepts/SensoRTOS_F446RE/SensoRTOS_F446RE/Core/Inc/Tasks" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Drivers

clean-Core-2f-Src-2f-Drivers:
	-$(RM) ./Core/Src/Drivers/delay.cyclo ./Core/Src/Drivers/delay.d ./Core/Src/Drivers/delay.o ./Core/Src/Drivers/delay.su ./Core/Src/Drivers/dht11.cyclo ./Core/Src/Drivers/dht11.d ./Core/Src/Drivers/dht11.o ./Core/Src/Drivers/dht11.su ./Core/Src/Drivers/font5x7.cyclo ./Core/Src/Drivers/font5x7.d ./Core/Src/Drivers/font5x7.o ./Core/Src/Drivers/font5x7.su ./Core/Src/Drivers/gpio.cyclo ./Core/Src/Drivers/gpio.d ./Core/Src/Drivers/gpio.o ./Core/Src/Drivers/gpio.su ./Core/Src/Drivers/hcsr04.cyclo ./Core/Src/Drivers/hcsr04.d ./Core/Src/Drivers/hcsr04.o ./Core/Src/Drivers/hcsr04.su ./Core/Src/Drivers/hcsr501.cyclo ./Core/Src/Drivers/hcsr501.d ./Core/Src/Drivers/hcsr501.o ./Core/Src/Drivers/hcsr501.su ./Core/Src/Drivers/i2c.cyclo ./Core/Src/Drivers/i2c.d ./Core/Src/Drivers/i2c.o ./Core/Src/Drivers/i2c.su ./Core/Src/Drivers/ssd1306.cyclo ./Core/Src/Drivers/ssd1306.d ./Core/Src/Drivers/ssd1306.o ./Core/Src/Drivers/ssd1306.su ./Core/Src/Drivers/uart.cyclo ./Core/Src/Drivers/uart.d ./Core/Src/Drivers/uart.o ./Core/Src/Drivers/uart.su ./Core/Src/Drivers/uart_cli.cyclo ./Core/Src/Drivers/uart_cli.d ./Core/Src/Drivers/uart_cli.o ./Core/Src/Drivers/uart_cli.su

.PHONY: clean-Core-2f-Src-2f-Drivers

