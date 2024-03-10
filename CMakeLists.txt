cmake_minimum_required(VERSION 3.5)
project(TwinFob CXX)
enable_testing()
set(CMAKE_CXX_STANDARD 17)

#select the release build type by default to get optimization flags
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
  message(STATUS "Build type not specified: defaulting to release.")
endif(NOT CMAKE_BUILD_TYPE)

set(CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE} CACHE STRING "")
set(TARGET_NAME ${PROJECT_NAME})

########################################################################
# Header and library resources needed to communicate with the device.
# These may be found within the build tree or in an external project.
########################################################################

########################################################################
# build the module
########################################################################
find_package(SoapySDR NO_MODULE  REQUIRED)

if (NOT SoapySDR_FOUND)
    message(WARNING "SoapySDR development files not found - skipping support")
    return()
endif ()

add_executable(${TARGET_NAME} src/main.cpp)
target_link_libraries(${TARGET_NAME} SoapySDR)