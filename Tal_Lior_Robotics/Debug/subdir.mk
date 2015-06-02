################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Manager.cpp \
../Map.cpp \
../MatrixCell.cpp \
../Particle.cpp \
../Point.cpp \
../Robot.cpp \
../SlamManager.cpp \
../main.cpp 

OBJS += \
./Manager.o \
./Map.o \
./MatrixCell.o \
./Particle.o \
./Point.o \
./Robot.o \
./SlamManager.o \
./main.o 

CPP_DEPS += \
./Manager.d \
./Map.d \
./MatrixCell.d \
./Particle.d \
./Point.d \
./Robot.d \
./SlamManager.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include/player-2.0 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


