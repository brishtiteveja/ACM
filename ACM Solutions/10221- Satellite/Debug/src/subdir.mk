################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/10221-\ Satellite.cpp 

OBJS += \
./src/10221-\ Satellite.o 

CPP_DEPS += \
./src/10221-\ Satellite.d 


# Each subdirectory must supply rules for building sources it contributes
src/10221-\ Satellite.o: ../src/10221-\ Satellite.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/10221- Satellite.d" -MT"src/10221-\ Satellite.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


