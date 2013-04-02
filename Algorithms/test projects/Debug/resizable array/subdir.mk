################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../resizable\ array/main.cpp 

OBJS += \
./resizable\ array/main.o 

CPP_DEPS += \
./resizable\ array/main.d 


# Each subdirectory must supply rules for building sources it contributes
resizable\ array/main.o: ../resizable\ array/main.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"resizable array/main.d" -MT"resizable\ array/main.d" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


