################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/136\ -\ Ugly\ numbers.cpp 

OBJS += \
./src/136\ -\ Ugly\ numbers.o 

CPP_DEPS += \
./src/136\ -\ Ugly\ numbers.d 


# Each subdirectory must supply rules for building sources it contributes
src/136\ -\ Ugly\ numbers.o: ../src/136\ -\ Ugly\ numbers.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/136 - Ugly numbers.d" -MT"src/136\ -\ Ugly\ numbers.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


