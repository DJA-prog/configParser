add_executable(create create.cpp)
target_link_libraries(create config_parser_lib)
set_target_properties(create PROPERTIES OUTPUT_NAME "example_create")

add_executable(read read.cpp)
target_link_libraries(read config_parser_lib)
set_target_properties(read PROPERTIES OUTPUT_NAME "example_read")

add_executable(alter alter.cpp)
target_link_libraries(alter config_parser_lib)
set_target_properties(alter PROPERTIES OUTPUT_NAME "example_alter")

# add_executable(delete delete.cpp)
# target_link_libraries(delete config_parser_lib)
# set_target_properties(delete PROPERTIES OUTPUT_NAME "example_delete")