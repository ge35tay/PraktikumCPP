################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../InterfaceSIM.cpp \
../KeyboardControl.cpp \
../PIDController.cpp \
../main.cpp 

OBJS += \
./InterfaceSIM.o \
./KeyboardControl.o \
./PIDController.o \
./main.o 

CPP_DEPS += \
./InterfaceSIM.d \
./KeyboardControl.d \
./PIDController.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I../ncurses.h -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


