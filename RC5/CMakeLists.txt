cmake_minimum_required(VERSION 3.0.0)
set (proj RC5)
project(${proj})
add_executable (${proj} rc5.cpp)
# target_compile_options(${proj} PUBLIC -Xclang -analyze)

