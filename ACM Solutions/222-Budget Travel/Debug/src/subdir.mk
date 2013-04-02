################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/222-Budget\ Travel.cpp 

OBJS += \
./src/222-Budget\ Travel.o 

CPP_DEPS += \
./src/222-Budget\ Travel.d 


# Each subdirectory must supply rules for building sources it contributes
src/222-Budget\ Travel.o: ../src/222-Budget\ Travel.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/222-Budget Travel.d" -MT"src/222-Budget\ Travel.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


