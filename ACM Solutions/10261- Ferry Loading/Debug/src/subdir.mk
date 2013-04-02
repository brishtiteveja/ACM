################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/10261-\ Ferry\ Loading.cpp 

OBJS += \
./src/10261-\ Ferry\ Loading.o 

CPP_DEPS += \
./src/10261-\ Ferry\ Loading.d 


# Each subdirectory must supply rules for building sources it contributes
src/10261-\ Ferry\ Loading.o: ../src/10261-\ Ferry\ Loading.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/10261- Ferry Loading.d" -MT"src/10261-\ Ferry\ Loading.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


