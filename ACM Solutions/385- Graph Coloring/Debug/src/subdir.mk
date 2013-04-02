################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/385-\ Graph\ Coloring.cpp 

OBJS += \
./src/385-\ Graph\ Coloring.o 

CPP_DEPS += \
./src/385-\ Graph\ Coloring.d 


# Each subdirectory must supply rules for building sources it contributes
src/385-\ Graph\ Coloring.o: ../src/385-\ Graph\ Coloring.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/385- Graph Coloring.d" -MT"src/385-\ Graph\ Coloring.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


