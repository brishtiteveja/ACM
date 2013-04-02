################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/10226-Hardwood\ Species.cpp 

OBJS += \
./src/10226-Hardwood\ Species.o 

CPP_DEPS += \
./src/10226-Hardwood\ Species.d 


# Each subdirectory must supply rules for building sources it contributes
src/10226-Hardwood\ Species.o: ../src/10226-Hardwood\ Species.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/10226-Hardwood Species.d" -MT"src/10226-Hardwood\ Species.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


