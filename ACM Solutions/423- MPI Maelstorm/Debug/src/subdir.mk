################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/423-\ MPI\ Maelstorm.cpp 

OBJS += \
./src/423-\ MPI\ Maelstorm.o 

CPP_DEPS += \
./src/423-\ MPI\ Maelstorm.d 


# Each subdirectory must supply rules for building sources it contributes
src/423-\ MPI\ Maelstorm.o: ../src/423-\ MPI\ Maelstorm.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/423- MPI Maelstorm.d" -MT"src/423-\ MPI\ Maelstorm.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


