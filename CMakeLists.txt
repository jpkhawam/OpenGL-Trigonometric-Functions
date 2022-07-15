cmake_minimum_required(VERSION 3.22)
project(TrigonometricFunctions)

set(CMAKE_CXX_STANDARD 14)

add_executable(TrigonometricFunctions main.cpp constants.h)

set(OpenGlLinkers -lglut -lGLU -lGL)
target_link_libraries(TrigonometricFunctions ${OpenGlLinkers})
