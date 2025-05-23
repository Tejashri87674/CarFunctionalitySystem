cmake_minimum_required(VERSION 4.0.1)
project(CarFunctionalitySystem1)



# This ensures the console subsystem is used (avoids WinMain error on Windows)
if(MINGW)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-subsystem,console")
endif()

# Main executable
add_executable(car_sim main.cpp car.cpp)

# Test runner executable
add_executable(test_runner test.cpp car.cpp)

