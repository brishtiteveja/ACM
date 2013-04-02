################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/750-\ 8Queen's\ Chess\ Problem.cpp 

OBJS += \
./src/750-\ 8Queen's\ Chess\ Problem.o 

CPP_DEPS += \
./src/750-\ 8Queen's\ Chess\ Problem.d 


# Each subdirectory must supply rules for building sources it contributes
src/750-\ 8Queen's\ Chess\ Problem.o: ../src/750-\ 8Queen's\ Chess\ Problem.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/750- 8Queen's Chess Problem.d" -MT"src/750-\ 8Queen's\ Chess\ Problem.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


