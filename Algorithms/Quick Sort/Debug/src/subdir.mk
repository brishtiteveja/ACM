################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Quick\ Sort.cpp 

OBJS += \
./src/Quick\ Sort.o 

CPP_DEPS += \
./src/Quick\ Sort.d 


# Each subdirectory must supply rules for building sources it contributes
src/Quick\ Sort.o: ../src/Quick\ Sort.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Quick Sort.d" -MT"src/Quick\ Sort.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


