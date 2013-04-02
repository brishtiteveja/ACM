################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/11308-Bankrupt\ Baker.cpp 

OBJS += \
./src/11308-Bankrupt\ Baker.o 

CPP_DEPS += \
./src/11308-Bankrupt\ Baker.d 


# Each subdirectory must supply rules for building sources it contributes
src/11308-Bankrupt\ Baker.o: ../src/11308-Bankrupt\ Baker.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/11308-Bankrupt Baker.d" -MT"src/11308-Bankrupt\ Baker.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


