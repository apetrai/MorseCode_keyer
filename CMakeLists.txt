cmake_minimum_required(VERSION 3.16)
project(MorseCode_Keyer LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

include_directories(include)

add_executable(MorseCodeKeyer 
            src/main.cpp
            src/Main_UI.cpp
            include/Main_UI.h)
target_link_libraries(MorseCodeKeyer PRIVATE sfml-graphics)
target_compile_features(MorseCodeKeyer PRIVATE cxx_std_17)

