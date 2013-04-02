################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Disjoint\ Set\ Eclipse.cpp 

OBJS += \
./src/Disjoint\ Set\ Eclipse.o 

CPP_DEPS += \
./src/Disjoint\ Set\ Eclipse.d 


# Each subdirectory must supply rules for building sources it contributes
src/Disjoint\ Set\ Eclipse.o: ../src/Disjoint\ Set\ Eclipse.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Disjoint Set Eclipse.d" -MT"src/Disjoint\ Set\ Eclipse.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


