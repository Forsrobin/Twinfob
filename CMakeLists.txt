# ================================ #
# === Set up build requirements == #
# ================================ #
cmake_minimum_required(VERSION 3.28.1)
project(TwinFob LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN On)

set(TARGET_NAME ${PROJECT_NAME})

# ================================ #
# === Set up build environment === #
# ================================ #
if (BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif ()

# ================================ #
# === Find required modules   ==== #
# ================================ #
# Modules that need's to be in root (Local projects)
find_package(SoapySDR NO_MODULE REQUIRED)

if (NOT SoapySDR_FOUND)
    message(WARNING "SoapySDR development files not found - skipping support")
    return()
endif (NOT SoapySDR_FOUND)

find_package(Qt6 REQUIRED)

if (NOT Qt6_FOUND)
  message(FATAL_ERROR "Qt6 not found")
endif (NOT Qt6_FOUND)


# ================================ #
# === Create build targets ======= #
# ================================ #
add_subdirectory(src)