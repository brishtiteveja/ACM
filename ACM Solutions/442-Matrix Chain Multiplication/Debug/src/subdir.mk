################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/442-Matrix\ Chain\ Multiplication.cpp 

OBJS += \
./src/442-Matrix\ Chain\ Multiplication.o 

CPP_DEPS += \
./src/442-Matrix\ Chain\ Multiplication.d 


# Each subdirectory must supply rules for building sources it contributes
src/442-Matrix\ Chain\ Multiplication.o: ../src/442-Matrix\ Chain\ Multiplication.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/442-Matrix Chain Multiplication.d" -MT"src/442-Matrix\ Chain\ Multiplication.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


