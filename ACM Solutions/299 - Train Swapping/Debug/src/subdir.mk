################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/299\ -\ Train\ Swapping.cpp 

OBJS += \
./src/299\ -\ Train\ Swapping.o 

CPP_DEPS += \
./src/299\ -\ Train\ Swapping.d 


# Each subdirectory must supply rules for building sources it contributes
src/299\ -\ Train\ Swapping.o: ../src/299\ -\ Train\ Swapping.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/299 - Train Swapping.d" -MT"src/299\ -\ Train\ Swapping.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


