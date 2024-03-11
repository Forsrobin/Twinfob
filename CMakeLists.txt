cmake_minimum_required(VERSION 3.5)
project(TwinFob)
set(CMAKE_C_STANDARD 99)

set(TARGET_NAME ${PROJECT_NAME})

find_package(SoapySDR NO_MODULE  REQUIRED)

if (NOT SoapySDR_FOUND)
    message(WARNING "SoapySDR development files not found - skipping support")
    return()
endif ()

add_executable(${TARGET_NAME} src/main.c)
target_link_libraries(${TARGET_NAME} SoapySDR)