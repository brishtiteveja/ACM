################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/130-Roman\ Roulette.cpp \
../src/130.cpp 

OBJS += \
./src/130-Roman\ Roulette.o \
./src/130.o 

CPP_DEPS += \
./src/130-Roman\ Roulette.d \
./src/130.d 


# Each subdirectory must supply rules for building sources it contributes
src/130-Roman\ Roulette.o: ../src/130-Roman\ Roulette.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/130-Roman Roulette.d" -MT"src/130-Roman\ Roulette.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


