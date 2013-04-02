################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/11239-Open\ Source.cpp 

OBJS += \
./src/11239-Open\ Source.o 

CPP_DEPS += \
./src/11239-Open\ Source.d 


# Each subdirectory must supply rules for building sources it contributes
src/11239-Open\ Source.o: ../src/11239-Open\ Source.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/11239-Open Source.d" -MT"src/11239-Open\ Source.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


