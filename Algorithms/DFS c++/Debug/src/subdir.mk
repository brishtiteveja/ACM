################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/DFS\ c++.cpp 

OBJS += \
./src/DFS\ c++.o 

CPP_DEPS += \
./src/DFS\ c++.d 


# Each subdirectory must supply rules for building sources it contributes
src/DFS\ c++.o: ../src/DFS\ c++.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/DFS c++.d" -MT"src/DFS\ c++.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


