# Write a CMakeLists that inlcudes all the files from 
#C:\Program Files\PothosSDR

cmake_minimum_required(VERSION 3.28)

project(Twinfob LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -IC:\\Program Files\\PothosSDR")

add_compile_definitions(
    $<$<CONFIG:Debug>:NDEBUG>
    SPDLOG_ACTIVE_LEVEL=$<IF:$<CONFIG:Debug>,SPDLOG_LEVEL_INFO,SPDLOG_LEVEL_WARN>
)

add_subdirectory(project)