include_directories(../src/inc)

add_executable(GcRay test.cpp)

target_link_libraries(GcPOV)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET GcRay PROPERTY CXX_STANDARD 20)
endif()