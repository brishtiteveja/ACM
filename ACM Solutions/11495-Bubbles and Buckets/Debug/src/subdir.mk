################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/11495-Bubbles\ and\ Buckets.cpp 

OBJS += \
./src/11495-Bubbles\ and\ Buckets.o 

CPP_DEPS += \
./src/11495-Bubbles\ and\ Buckets.d 


# Each subdirectory must supply rules for building sources it contributes
src/11495-Bubbles\ and\ Buckets.o: ../src/11495-Bubbles\ and\ Buckets.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/11495-Bubbles and Buckets.d" -MT"src/11495-Bubbles\ and\ Buckets.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


