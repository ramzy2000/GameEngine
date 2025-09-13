cmake_minimum_required(VERSION 3.28)
project(2DGameEngine LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)

# SFML
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

# Box2D
FetchContent_Declare(Box2D
    GIT_REPOSITORY https://github.com/erincatto/box2d.git
    GIT_TAG v2.4.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(Box2D)

# Grab all source files
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    "src/*.cpp"
    "src/*.h"
)

# Create the executable target
add_executable(main ${SOURCES})

# Organize files in Visual Studio filters
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/src" FILES ${SOURCES})

# Compiler features
target_compile_features(main PRIVATE cxx_std_17)

# Link libraries
target_link_libraries(main
    PRIVATE
        SFML::Graphics
        box2d
)

# Include directories
target_include_directories(main
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)