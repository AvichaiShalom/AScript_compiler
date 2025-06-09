cmake_minimum_required(VERSION 3.27.1)
project(AScript_compiler)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_WIN32_EXECUTABLE FALSE)

file(GLOB SOURCES "src/*.cpp")
include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(AScript ${SOURCES})

set_target_properties(AScript PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
