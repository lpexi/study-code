cmake_minimum_required(VERSION 3.16)

project(grade_report LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(grade_report
    grading_project/src/main.cpp
    grading_project/src/report_utils.cpp
)

target_include_directories(grade_report
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/grading_project/include
)

if(MSVC)
    target_compile_options(grade_report PRIVATE /W4 /permissive-)
else()
    target_compile_options(grade_report PRIVATE -Wall -Wextra -pedantic)
endif()
