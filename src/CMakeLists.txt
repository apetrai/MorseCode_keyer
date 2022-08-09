cmake_minimum_required(VERSION 3.1...3.23)


project(
  MorseCode_translator
  VERSION 1.0
  LANGUAGES CXX)


add_library(main main.cpp)

add_executable(MorseCode_translator main.cpp)
