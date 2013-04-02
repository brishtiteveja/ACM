################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/594-One\ Two\ Three\ Little\ Endian.cpp 

OBJS += \
./src/594-One\ Two\ Three\ Little\ Endian.o 

CPP_DEPS += \
./src/594-One\ Two\ Three\ Little\ Endian.d 


# Each subdirectory must supply rules for building sources it contributes
src/594-One\ Two\ Three\ Little\ Endian.o: ../src/594-One\ Two\ Three\ Little\ Endian.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/594-One Two Three Little Endian.d" -MT"src/594-One\ Two\ Three\ Little\ Endian.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


