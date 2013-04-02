################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/127-\ Accordian\ Patience.cpp 

OBJS += \
./src/127-\ Accordian\ Patience.o 

CPP_DEPS += \
./src/127-\ Accordian\ Patience.d 


# Each subdirectory must supply rules for building sources it contributes
src/127-\ Accordian\ Patience.o: ../src/127-\ Accordian\ Patience.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/127- Accordian Patience.d" -MT"src/127-\ Accordian\ Patience.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


