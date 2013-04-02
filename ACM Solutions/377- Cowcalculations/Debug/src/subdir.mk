################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/377-\ Cowcalculations.cpp 

OBJS += \
./src/377-\ Cowcalculations.o 

CPP_DEPS += \
./src/377-\ Cowcalculations.d 


# Each subdirectory must supply rules for building sources it contributes
src/377-\ Cowcalculations.o: ../src/377-\ Cowcalculations.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/377- Cowcalculations.d" -MT"src/377-\ Cowcalculations.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


