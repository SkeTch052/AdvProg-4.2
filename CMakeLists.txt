cmake_minimum_required(VERSION 3.20)
project (MyProject2)

add_subdirectory(Catch2)
add_executable(MyProject2 main-test2.cpp ListFunc.cpp) 
target_link_libraries(MyProject2 PRIVATE Catch2::Catch2)