################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/10810-\ Ultra\ Quicksort.cpp 

OBJS += \
./src/10810-\ Ultra\ Quicksort.o 

CPP_DEPS += \
./src/10810-\ Ultra\ Quicksort.d 


# Each subdirectory must supply rules for building sources it contributes
src/10810-\ Ultra\ Quicksort.o: ../src/10810-\ Ultra\ Quicksort.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/10810- Ultra Quicksort.d" -MT"src/10810-\ Ultra\ Quicksort.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


