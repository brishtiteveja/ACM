################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Boost\ Test.cpp 

OBJS += \
./src/Boost\ Test.o 

CPP_DEPS += \
./src/Boost\ Test.d 


# Each subdirectory must supply rules for building sources it contributes
src/Boost\ Test.o: ../src/Boost\ Test.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/Users/zehadyzbdullahkhan/Documents/workspace/programming language/C,C++/libraries/boost_1_53_0" -I"/Users/zehadyzbdullahkhan/Documents/workspace/programming language/C,C++/libraries/boost_1_53_0/boost" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Boost Test.d" -MT"src/Boost\ Test.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


