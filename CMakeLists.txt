cmake_minimum_required(VERSION 3.10)
project(mini_db VERSION 0.1)

 add_library(mini_db_lib
     src/parser.cpp
 )

target_include_directories(mini_db_lib PUBLIC src/include)

add_executable(mini_db src/main.cpp)

target_link_libraries(mini_db PRIVATE mini_db_lib)
