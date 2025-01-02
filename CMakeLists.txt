# CMakeList.txt: GcRay 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

# 如果支持，请为 MSVC 编译器启用热重载。
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("GcRay")

# .exe's output path
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# .lib's output path
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# 将源代码添加到此项目的可执行文件。
include_directories(${PROJECT_SOURCE_DIR}/src/inc)

# link libs
link_directories(${PROJECT_SOURCE_DIR}/lib)

add_subdirectory(${PROJECT_SOURCE_DIR}/src)

# about example
add_subdirectory(${PROJECT_SOURCE_DIR}/example)

# TODO: 如有需要，请添加测试并安装目标。
