################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../cool\ input:output/main.cpp 

OBJS += \
./cool\ input:output/main.o 

CPP_DEPS += \
./cool\ input:output/main.d 


# Each subdirectory must supply rules for building sources it contributes
cool\ input:output/main.o: ../cool\ input:output/main.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"cool input:output/main.d" -MT"cool\ input:output/main.d" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


