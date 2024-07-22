cmake_minimum_required(VERSION 3.10)
project(MorseCode_keyer)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(MorseCode_keyer src/main.cpp "include/Main_UI.h" "src/MAIN_UI.cpp")

# Specify the path to SFML
set(SFML_DIR "C:\\SFML\\lib\\cmake\\SFML") # Update this path to your SFML installation


set(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH};C:/SFML/lib/cmake/SFML")

# Find SFML libraries
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Link SFML libraries
target_link_libraries(MorseCode_keyer sfml-graphics sfml-window sfml-system)


