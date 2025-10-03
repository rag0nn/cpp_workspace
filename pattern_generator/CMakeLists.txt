cmake_minimum_required(VERSION 3.10)
project(PatternGenerator)

# Packages
find_package(OpenCV REQUIRED)
find_package(pybind11 REQUIRED)


# Include paths
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/include)

# -----------------------
# Normal executable
set(TERMINAL_SOURCES
    src/main.cpp 
    src/Cyclical.cpp
)
add_executable(pattern_generator ${TERMINAL_SOURCES})
target_link_libraries(pattern_generator PRIVATE ${OpenCV_LIBS})

# -----------------------
# Pybind11 module
pybind11_add_module(cyclicalGenerator bindings/bindings.cpp src/Cyclical.cpp)
target_link_libraries(cyclicalGenerator PRIVATE ${OpenCV_LIBS})
target_include_directories(cyclicalGenerator PRIVATE ${CMAKE_SOURCE_DIR}/include)
