################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/612-DNA\ Sorting.cpp 

OBJS += \
./src/612-DNA\ Sorting.o 

CPP_DEPS += \
./src/612-DNA\ Sorting.d 


# Each subdirectory must supply rules for building sources it contributes
src/612-DNA\ Sorting.o: ../src/612-DNA\ Sorting.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/612-DNA Sorting.d" -MT"src/612-DNA\ Sorting.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


