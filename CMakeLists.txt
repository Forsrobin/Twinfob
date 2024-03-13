# ================================ #
# === Set up build requirements == #
# ================================ #
cmake_minimum_required(VERSION 3.5)
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
add_subdirectory(modules)

# ================================ #
# === Create build targets ======= #
# ================================ #
add_subdirectory(src)