################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/misc.c \
../src/red_black_tree.c \
../src/stack.c \
../src/test_red_black_tree.c 

OBJS += \
./src/misc.o \
./src/red_black_tree.o \
./src/stack.o \
./src/test_red_black_tree.o 

C_DEPS += \
./src/misc.d \
./src/red_black_tree.d \
./src/stack.d \
./src/test_red_black_tree.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


