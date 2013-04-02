################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/475-\ The\ Wedding.cpp 

OBJS += \
./src/475-\ The\ Wedding.o 

CPP_DEPS += \
./src/475-\ The\ Wedding.d 


# Each subdirectory must supply rules for building sources it contributes
src/475-\ The\ Wedding.o: ../src/475-\ The\ Wedding.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/475- The Wedding.d" -MT"src/475-\ The\ Wedding.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


