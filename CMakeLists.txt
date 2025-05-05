cmake_minimum_required(VERSION 3.16)
project(MorseCodeKeyer LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(MorseCodeKeyer
    ${CMAKE_SOURCE_DIR}/src/main.cpp
    ${CMAKE_SOURCE_DIR}/include/textbox.h
    ${CMAKE_SOURCE_DIR}/src/textbox.cpp
    ${CMAKE_SOURCE_DIR}/include/render.h
    ${CMAKE_SOURCE_DIR}/include/button.h
    ${CMAKE_SOURCE_DIR}/src/button.cpp
)

target_link_libraries(MorseCodeKeyer PRIVATE sfml-graphics)
target_compile_features(MorseCodeKeyer PRIVATE cxx_std_17)

# Include OpenAL
include_directories(${OPENAL_INCLUDE_DIR})
target_link_libraries(MorseCodeKeyer PRIVATE ${OPENAL_LIBRARY})

include_directories(${OPENGL_INCLUDE_DIR})
target_link_libraries(MorseCodeKeyer PRIVATE ${OPENGL_LIBRARY})
