cmake_minimum_required(VERSION 3.10)
project(PatternGenerator)

# packages
find_package(OpenCV REQUIRED)

# include 
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(include)

set(TERMINAL_SOURCES
    src/main.cpp 
    src/Cyclical.cpp
)

# execution
add_executable(pattern_generator ${TERMINAL_SOURCES})

target_link_libraries(pattern_generator
    PRIVATE
        ${OpenCV_LIBS}
)