cmake_minimum_required(VERSION 3.24)

# set the project name and version
project(design_pattern_examples VERSION 0.0.1)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the source folders
# add_subdirectory(3rdparty)
add_subdirectory(src)
# add_subdirectory(test)