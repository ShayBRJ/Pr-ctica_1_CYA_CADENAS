cmake_minimum_required(VERSION 3.1)  # Mandatory

# set the project name 
project(Cadena                # Mandatory
    VERSION 1.0
    DESCRIPTION "Cadena Class"
    LANGUAGES CXX)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17) 						# Use c++17
set(CMAKE_CXX_STANDARD_REQUIRED True)

# tell cmake to output binaries here:
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# Debug and release flags
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# tell cmake where to look for *.h files
include_directories(${PROJECT_SOURCE_DIR}/include)


# Adds an executable target called "CadenaMain" to be built from the source files listed in the command invocation.
add_executable(CadenaMain
src/main.cc
src/Cadena.cc
src/Alfabeto.cc
src/Symbol.cc
include/Alfabeto.h
include/Cadena.h
include/Symbol.h
        )


# Add expected compiler features to a target.
target_compile_features(CadenaMain PRIVATE cxx_std_17)

# Add compile options to a target.
target_compile_options(CadenaMain PRIVATE )