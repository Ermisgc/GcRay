include_directories(../src/inc/pov)

add_executable(GcRay test.cpp)

target_link_libraries(GcRay GcPOV)
