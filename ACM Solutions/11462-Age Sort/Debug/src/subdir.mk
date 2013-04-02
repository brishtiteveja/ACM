################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/11462-Age\ Sort.cpp 

OBJS += \
./src/11462-Age\ Sort.o 

CPP_DEPS += \
./src/11462-Age\ Sort.d 


# Each subdirectory must supply rules for building sources it contributes
src/11462-Age\ Sort.o: ../src/11462-Age\ Sort.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/11462-Age Sort.d" -MT"src/11462-Age\ Sort.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


