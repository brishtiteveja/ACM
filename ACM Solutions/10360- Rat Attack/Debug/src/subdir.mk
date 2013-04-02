################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/10360-\ Rat\ Attack.cpp 

OBJS += \
./src/10360-\ Rat\ Attack.o 

CPP_DEPS += \
./src/10360-\ Rat\ Attack.d 


# Each subdirectory must supply rules for building sources it contributes
src/10360-\ Rat\ Attack.o: ../src/10360-\ Rat\ Attack.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/10360- Rat Attack.d" -MT"src/10360-\ Rat\ Attack.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


