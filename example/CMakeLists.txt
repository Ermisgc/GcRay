include_directories(../src/inc)

add_executable(GcRay test.cpp)

target_link_libraries(GcRay GcPOV)
