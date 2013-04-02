################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Sort\ All.cpp 

OBJS += \
./src/Sort\ All.o 

CPP_DEPS += \
./src/Sort\ All.d 


# Each subdirectory must supply rules for building sources it contributes
src/Sort\ All.o: ../src/Sort\ All.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Sort All.d" -MT"src/Sort\ All.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


