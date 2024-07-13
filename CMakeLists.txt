cmake_minimum_required(VERSION 3.21)
project(Game-of-Life)

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME})
add_subdirectory(src)

find_package(SDL2 REQUIRED)

target_include_directories(${PROJECT_NAME} PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL2_LIBRARIES})

if (WIN32)
    add_custom_command(
            TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND "${CMAKE_COMMAND}" -E copy_if_different $<TARGET_RUNTIME_DLLS:${PROJECT_NAME}> $<TARGET_FILE_DIR:${PROJECT_NAME}>
            VERBATIM
    )
endif ()
