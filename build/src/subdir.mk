################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/main.cc \
../src/parser.cc \
../src/trieTree.cc \

OBJS += \
./src/main.o \
./src/parser.o \
./src/trieTree.o \

CPP_DEPS += \
./src/main.d \
./src/parser.d \
./src/trieTree.d \

# Each subdirectory must supply rules for building src it contributes
src/%.o: ../src/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<" -std=c++11 -pthread
	@echo ' '


