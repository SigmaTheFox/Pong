cmake_minimum_required(VERSION 3.27)
project(Pong C)
set(CMAKE_C_STANDARD 99)

set(INCLUDE_DIR include)
file(GLOB_RECURSE HEADER_FILES ${INCLUDE_DIR}/*.h)
file(GLOB_RECURSE SOURCE_FILES src/*.c)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/sfx" DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}/build/")

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE ${SOURCE_FILES} ${HEADER_FILES})
target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE ${INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

target_compile_definitions(${PROJECT_NAME} PUBLIC SFX_PATH="./sfx/")
