cmake_minimum_required(VERSION 3.12)
project(ConfigParser)

set(CMAKE_CXX_STANDARD 11)

include_directories(src)

add_library(config_parser_lib
        src/ConfigFile.cpp
        src/ConfigParser.cpp)

add_executable(test_config_parser
        tests/test_config_parser.cpp)

target_link_libraries(test_config_parser config_parser_lib)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/../bin)