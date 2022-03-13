cmake_minimum_required(VERSION 3.19)
project(project)

set(CMAKE_CXX_STANDARD 14)

add_executable(exe main.cpp negative_binomial_table.cpp negative_binomial_bernoulli.cpp chi_square_test.cpp distribution.cpp)