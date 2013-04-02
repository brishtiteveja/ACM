################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/10069-Distinct\ Subsequence.cpp 

OBJS += \
./src/10069-Distinct\ Subsequence.o 

CPP_DEPS += \
./src/10069-Distinct\ Subsequence.d 


# Each subdirectory must supply rules for building sources it contributes
src/10069-Distinct\ Subsequence.o: ../src/10069-Distinct\ Subsequence.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/10069-Distinct Subsequence.d" -MT"src/10069-Distinct\ Subsequence.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


