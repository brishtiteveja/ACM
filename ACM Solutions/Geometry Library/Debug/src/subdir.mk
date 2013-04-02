################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Geometry\ Library.cpp 

OBJS += \
./src/Geometry\ Library.o 

CPP_DEPS += \
./src/Geometry\ Library.d 


# Each subdirectory must supply rules for building sources it contributes
src/Geometry\ Library.o: ../src/Geometry\ Library.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Geometry Library.d" -MT"src/Geometry\ Library.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


