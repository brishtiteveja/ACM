################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/KMP\ string\ search.cpp 

OBJS += \
./src/KMP\ string\ search.o 

CPP_DEPS += \
./src/KMP\ string\ search.d 


# Each subdirectory must supply rules for building sources it contributes
src/KMP\ string\ search.o: ../src/KMP\ string\ search.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/KMP string search.d" -MT"src/KMP\ string\ search.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


