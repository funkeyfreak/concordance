cmake_minimum_required(VERSION 3.6)
project(concordance)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c hashHelper.c hashHelper.h fileHelper.c fileHelper.h)
add_executable(concordance ${SOURCE_FILES})