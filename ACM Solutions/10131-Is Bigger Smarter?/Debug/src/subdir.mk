################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/10131-Is\ Bigger\ Smarter?.cpp 

OBJS += \
./src/10131-Is\ Bigger\ Smarter?.o 

CPP_DEPS += \
./src/10131-Is\ Bigger\ Smarter?.d 


# Each subdirectory must supply rules for building sources it contributes
src/10131-Is\ Bigger\ Smarter?.o: ../src/10131-Is\ Bigger\ Smarter?.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/10131-Is Bigger Smarter?.d" -MT"src/10131-Is\ Bigger\ Smarter?.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


