################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include stack/subdir.mk
-include stack/build/stack.build/Debug/stack.build/Objects-normal/x86_64/subdir.mk
-include resizable\ array/subdir.mk
-include resizable\ array/build/resizable\ array.build/Debug/resizable\ array.build/Objects-normal/x86_64/subdir.mk
-include queue/subdir.mk
-include queue/build/queue.build/Debug/queue.build/Objects-normal/x86_64/subdir.mk
-include list\ container/subdir.mk
-include list\ container/build/list\ container.build/Debug/list\ container.build/Objects-normal/x86_64/subdir.mk
-include cool\ input:output/subdir.mk
-include cool\ input:output/build/cool\ input:output.build/Debug/cool\ input:output.build/Objects-normal/x86_64/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: input-output

# Tool invocations
input-output: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MacOS X C++ Linker'
	g++  -o "input-output" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C++_DEPS)$(OBJS)$(C_DEPS)$(CC_DEPS)$(CPP_DEPS)$(EXECUTABLES)$(CXX_DEPS)$(C_UPPER_DEPS) input-output
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
