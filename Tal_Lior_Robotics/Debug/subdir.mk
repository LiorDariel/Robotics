################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ConfigFile.cpp \
../Manager.cpp \
../Map.cpp \
../MatrixCell.cpp \
../Particle.cpp \
../Point.cpp \
../Robot.cpp \
../SlamManager.cpp \
../lodepng.cpp \
../main.cpp 

OBJS += \
./ConfigFile.o \
./Manager.o \
./Map.o \
./MatrixCell.o \
./Particle.o \
./Point.o \
./Robot.o \
./SlamManager.o \
./lodepng.o \
./main.o 

CPP_DEPS += \
./ConfigFile.d \
./Manager.d \
./Map.d \
./MatrixCell.d \
./Particle.d \
./Point.d \
./Robot.d \
./SlamManager.d \
./lodepng.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include/player-2.0 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


