aux_source_directory(. SRC_LIST)

# generate a library
add_library(GcPOV SHARED ${SRC_LIST})

include_directories(../inc/pov)