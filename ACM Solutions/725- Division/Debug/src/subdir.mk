################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/725-\ Division.cpp 

OBJS += \
./src/725-\ Division.o 

CPP_DEPS += \
./src/725-\ Division.d 


# Each subdirectory must supply rules for building sources it contributes
src/725-\ Division.o: ../src/725-\ Division.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/725- Division.d" -MT"src/725-\ Division.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


