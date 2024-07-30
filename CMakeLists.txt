cmake_minimum_required(VERSION 3.16)
project(MorseCodeKeyer LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

# Find OpenAL
find_package(OpenAL REQUIRED)

add_executable(MorseCodeKeyer ${CMAKE_SOURCE_DIR}/src/main.cpp ${CMAKE_SOURCE_DIR}/include/Main_UI.h ${CMAKE_SOURCE_DIR}/src/Main_UI.cpp)
target_link_libraries(MorseCodeKeyer PRIVATE sfml-graphics)
target_compile_features(MorseCodeKeyer PRIVATE cxx_std_17)

# Include OpenAL
include_directories(${OPENAL_INCLUDE_DIR})
target_link_libraries(MorseCodeKeyer PRIVATE ${OPENAL_LIBRARY})
