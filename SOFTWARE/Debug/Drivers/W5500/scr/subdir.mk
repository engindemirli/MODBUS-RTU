################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/W5500/scr/socket.c \
../Drivers/W5500/scr/w5500.c \
../Drivers/W5500/scr/wizchip_conf.c 

OBJS += \
./Drivers/W5500/scr/socket.o \
./Drivers/W5500/scr/w5500.o \
./Drivers/W5500/scr/wizchip_conf.o 

C_DEPS += \
./Drivers/W5500/scr/socket.d \
./Drivers/W5500/scr/w5500.d \
./Drivers/W5500/scr/wizchip_conf.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/W5500/scr/%.o: ../Drivers/W5500/scr/%.c Drivers/W5500/scr/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F072xB -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I"G:/PROJECT/OKUL_PROJE/SOFTWARE/Drivers/W5500" -I"G:/PROJECT/OKUL_PROJE/SOFTWARE/Drivers/W5500/inc" -I"G:/PROJECT/OKUL_PROJE/SOFTWARE/Drivers/W5500/scr" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-W5500-2f-scr

clean-Drivers-2f-W5500-2f-scr:
	-$(RM) ./Drivers/W5500/scr/socket.d ./Drivers/W5500/scr/socket.o ./Drivers/W5500/scr/w5500.d ./Drivers/W5500/scr/w5500.o ./Drivers/W5500/scr/wizchip_conf.d ./Drivers/W5500/scr/wizchip_conf.o

.PHONY: clean-Drivers-2f-W5500-2f-scr

