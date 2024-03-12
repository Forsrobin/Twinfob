# ================================ #
# === Set up build requirements == #
# ================================ #
cmake_minimum_required(VERSION 3.5)
project(TwinFob)
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
# === Find required libraries ==== #
# ================================ #
find_package(SoapySDR NO_MODULE  REQUIRED)

if (NOT SoapySDR_FOUND)
    message(WARNING "SoapySDR development files not found - skipping support")
    return()
endif ()

# ================================ #
# === Create build targets ======= #
# ================================ #
add_executable(${TARGET_NAME} src/main.cpp)
target_link_libraries(${TARGET_NAME} SoapySDR)
install(TARGETS ${TARGET_NAME} DESTINATION ${CMAKE_INSTALL_BINDIR})