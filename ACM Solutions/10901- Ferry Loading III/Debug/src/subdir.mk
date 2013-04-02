################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/10901-\ Ferry\ Loading\ III.cpp 

OBJS += \
./src/10901-\ Ferry\ Loading\ III.o 

CPP_DEPS += \
./src/10901-\ Ferry\ Loading\ III.d 


# Each subdirectory must supply rules for building sources it contributes
src/10901-\ Ferry\ Loading\ III.o: ../src/10901-\ Ferry\ Loading\ III.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/10901- Ferry Loading III.d" -MT"src/10901-\ Ferry\ Loading\ III.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


