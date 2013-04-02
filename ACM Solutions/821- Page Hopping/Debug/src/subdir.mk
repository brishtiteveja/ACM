################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/821-\ page\ hopping.cpp 

OBJS += \
./src/821-\ page\ hopping.o 

CPP_DEPS += \
./src/821-\ page\ hopping.d 


# Each subdirectory must supply rules for building sources it contributes
src/821-\ page\ hopping.o: ../src/821-\ page\ hopping.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/821- page hopping.d" -MT"src/821-\ page\ hopping.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


