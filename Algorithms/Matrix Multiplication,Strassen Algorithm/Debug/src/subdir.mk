################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Matrix\ Multiplication,Strassen\ Algorithm.cpp 

OBJS += \
./src/Matrix\ Multiplication,Strassen\ Algorithm.o 

CPP_DEPS += \
./src/Matrix\ Multiplication,Strassen\ Algorithm.d 


# Each subdirectory must supply rules for building sources it contributes
src/Matrix\ Multiplication,Strassen\ Algorithm.o: ../src/Matrix\ Multiplication,Strassen\ Algorithm.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Matrix Multiplication,Strassen Algorithm.d" -MT"src/Matrix\ Multiplication,Strassen\ Algorithm.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


