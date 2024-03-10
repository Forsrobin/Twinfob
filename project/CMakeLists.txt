# Custom target to generate the Slint C++ API from the Slint source files.
set(TARGET_NAME ${PROJECT_NAME})


add_executable(${TARGET_NAME} src/main.cpp)


# On Windows, copy the Slint DLL next to the application binary so that it's found.

if (WIN32)
    target_compile_definitions(${TARGET_NAME} PRIVATE NOMINMAX)

    add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_RUNTIME_DLLS:${TARGET_NAME}>
        $<TARGET_FILE_DIR:${TARGET_NAME}> COMMAND_EXPAND_LISTS
    )
endif()