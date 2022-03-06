################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/global.c \
../Core/Src/http_server.c \
../Core/Src/main.c \
../Core/Src/server_sett.c \
../Core/Src/stm32f0xx_hal_msp.c \
../Core/Src/stm32f0xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f0xx.c \
../Core/Src/tcp_server.c \
../Core/Src/user.c 

OBJS += \
./Core/Src/global.o \
./Core/Src/http_server.o \
./Core/Src/main.o \
./Core/Src/server_sett.o \
./Core/Src/stm32f0xx_hal_msp.o \
./Core/Src/stm32f0xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f0xx.o \
./Core/Src/tcp_server.o \
./Core/Src/user.o 

C_DEPS += \
./Core/Src/global.d \
./Core/Src/http_server.d \
./Core/Src/main.d \
./Core/Src/server_sett.d \
./Core/Src/stm32f0xx_hal_msp.d \
./Core/Src/stm32f0xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f0xx.d \
./Core/Src/tcp_server.d \
./Core/Src/user.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F072xB -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I"G:/PROJECT/OKUL_PROJE/SOFTWARE/Drivers/W5500" -I"G:/PROJECT/OKUL_PROJE/SOFTWARE/Drivers/W5500/inc" -I"G:/PROJECT/OKUL_PROJE/SOFTWARE/Drivers/W5500/scr" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/global.d ./Core/Src/global.o ./Core/Src/http_server.d ./Core/Src/http_server.o ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/server_sett.d ./Core/Src/server_sett.o ./Core/Src/stm32f0xx_hal_msp.d ./Core/Src/stm32f0xx_hal_msp.o ./Core/Src/stm32f0xx_it.d ./Core/Src/stm32f0xx_it.o ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/system_stm32f0xx.d ./Core/Src/system_stm32f0xx.o ./Core/Src/tcp_server.d ./Core/Src/tcp_server.o ./Core/Src/user.d ./Core/Src/user.o

.PHONY: clean-Core-2f-Src

