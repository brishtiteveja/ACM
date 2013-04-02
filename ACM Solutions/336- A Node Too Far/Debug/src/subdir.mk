################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/336-\ A\ Node\ Too\ Far.cpp 

OBJS += \
./src/336-\ A\ Node\ Too\ Far.o 

CPP_DEPS += \
./src/336-\ A\ Node\ Too\ Far.d 


# Each subdirectory must supply rules for building sources it contributes
src/336-\ A\ Node\ Too\ Far.o: ../src/336-\ A\ Node\ Too\ Far.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/336- A Node Too Far.d" -MT"src/336-\ A\ Node\ Too\ Far.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


