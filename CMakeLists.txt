cmake_minimum_required(VERSION 3.10)
project(filemanager VERSION 0.0.1 DESCRIPTION "File Manager by shewants")

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

file(GLOB SOURCES "src/*.c")
file(GLOB HEADERS "src/*.h")

add_executable(filemanager ${SOURCES} ${HEADERS})