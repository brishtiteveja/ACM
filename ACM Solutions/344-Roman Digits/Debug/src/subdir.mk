################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/344-Roman\ Digits.cpp 

OBJS += \
./src/344-Roman\ Digits.o 

CPP_DEPS += \
./src/344-Roman\ Digits.d 


# Each subdirectory must supply rules for building sources it contributes
src/344-Roman\ Digits.o: ../src/344-Roman\ Digits.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/344-Roman Digits.d" -MT"src/344-Roman\ Digits.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


