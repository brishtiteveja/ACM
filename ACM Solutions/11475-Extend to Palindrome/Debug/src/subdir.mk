################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/11475-Extend\ to\ Palindrome.cpp 

OBJS += \
./src/11475-Extend\ to\ Palindrome.o 

CPP_DEPS += \
./src/11475-Extend\ to\ Palindrome.d 


# Each subdirectory must supply rules for building sources it contributes
src/11475-Extend\ to\ Palindrome.o: ../src/11475-Extend\ to\ Palindrome.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/11475-Extend to Palindrome.d" -MT"src/11475-Extend\ to\ Palindrome.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


