cmake_minimum_required (VERSION 3.5)

# 可以指定更多的信息，比如加一个版本号
project ("GcRay")
SET(PROJECT_VERSION 1.0.0.1)

# using gdb
set(CMAKE_BUILD_TYPE "Debug")

# .exe's output path
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# .lib's output path
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# header files' searching path
# include_directories(${PROJECT_SOURCE_DIR}/src/include)
include_directories(${PROJECT_SOURCE_DIR}/example)

# link libs
link_directories(${PROJECT_SOURCE_DIR}/lib)

# about rpc 
add_subdirectory(src)

add_subdirectory(example)

# about example