################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Tasks/Task_DHT11.c \
../Core/Src/Tasks/Task_HCSR04.c \
../Core/Src/Tasks/Task_HCSR501.c \
../Core/Src/Tasks/Task_LED.c \
../Core/Src/Tasks/Task_UART.c \
../Core/Src/Tasks/tasks.c 

OBJS += \
./Core/Src/Tasks/Task_DHT11.o \
./Core/Src/Tasks/Task_HCSR04.o \
./Core/Src/Tasks/Task_HCSR501.o \
./Core/Src/Tasks/Task_LED.o \
./Core/Src/Tasks/Task_UART.o \
./Core/Src/Tasks/tasks.o 

C_DEPS += \
./Core/Src/Tasks/Task_DHT11.d \
./Core/Src/Tasks/Task_HCSR04.d \
./Core/Src/Tasks/Task_HCSR501.d \
./Core/Src/Tasks/Task_LED.d \
./Core/Src/Tasks/Task_UART.d \
./Core/Src/Tasks/tasks.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Tasks/%.o Core/Src/Tasks/%.su Core/Src/Tasks/%.cyclo: ../Core/Src/Tasks/%.c Core/Src/Tasks/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"D:/Firmware/STM32/FreeRTOS_Concepts/SensoRTOS_F446RE/SensoRTOS_F446RE/Core/Inc/Drivers" -I"D:/Firmware/STM32/FreeRTOS_Concepts/SensoRTOS_F446RE/SensoRTOS_F446RE/Core/Inc/Tasks" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Tasks

clean-Core-2f-Src-2f-Tasks:
	-$(RM) ./Core/Src/Tasks/Task_DHT11.cyclo ./Core/Src/Tasks/Task_DHT11.d ./Core/Src/Tasks/Task_DHT11.o ./Core/Src/Tasks/Task_DHT11.su ./Core/Src/Tasks/Task_HCSR04.cyclo ./Core/Src/Tasks/Task_HCSR04.d ./Core/Src/Tasks/Task_HCSR04.o ./Core/Src/Tasks/Task_HCSR04.su ./Core/Src/Tasks/Task_HCSR501.cyclo ./Core/Src/Tasks/Task_HCSR501.d ./Core/Src/Tasks/Task_HCSR501.o ./Core/Src/Tasks/Task_HCSR501.su ./Core/Src/Tasks/Task_LED.cyclo ./Core/Src/Tasks/Task_LED.d ./Core/Src/Tasks/Task_LED.o ./Core/Src/Tasks/Task_LED.su ./Core/Src/Tasks/Task_UART.cyclo ./Core/Src/Tasks/Task_UART.d ./Core/Src/Tasks/Task_UART.o ./Core/Src/Tasks/Task_UART.su ./Core/Src/Tasks/tasks.cyclo ./Core/Src/Tasks/tasks.d ./Core/Src/Tasks/tasks.o ./Core/Src/Tasks/tasks.su

.PHONY: clean-Core-2f-Src-2f-Tasks

