# ================================ #
# === Create build targets ======= #
# ================================ #
add_executable(${TARGET_NAME} main.cpp sdr.cpp)

target_link_libraries(${TARGET_NAME} PRIVATE qt::qt SoapySDR)

# Install
install(TARGETS ${TARGET_NAME} DESTINATION ${CMAKE_INSTALL_BINDIR})

if (WIN32)
    add_custom_command(TARGET ${TARGET_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:${TARGET_NAME}> $<TARGET_FILE_DIR:${TARGET_NAME}> COMMAND_EXPAND_LISTS)
endif()