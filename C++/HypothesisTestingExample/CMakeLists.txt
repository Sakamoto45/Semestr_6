cmake_minimum_required(VERSION 3.19)
project(project)

set(CMAKE_CXX_STANDARD 14)

add_executable(exe main.cpp chisquare.cpp document.cpp nb_bernoulli.cpp nb_distribution.cpp nb_generator.cpp nb_inverse.cpp nb_table.cpp probdist.cpp)