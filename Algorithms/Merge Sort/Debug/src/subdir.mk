################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Merge\ Sort.cpp \
../src/merge\ sort\ previous.cpp 

OBJS += \
./src/Merge\ Sort.o \
./src/merge\ sort\ previous.o 

CPP_DEPS += \
./src/Merge\ Sort.d \
./src/merge\ sort\ previous.d 


# Each subdirectory must supply rules for building sources it contributes
src/Merge\ Sort.o: ../src/Merge\ Sort.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Merge Sort.d" -MT"src/Merge\ Sort.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/merge\ sort\ previous.o: ../src/merge\ sort\ previous.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/merge sort previous.d" -MT"src/merge\ sort\ previous.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


