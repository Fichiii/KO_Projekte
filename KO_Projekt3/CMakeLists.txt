cmake_minimum_required(VERSION 4.0)
project(KO_Projekt3)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(KO_Projekt3
        Instance.cpp
        Instance.hpp
        main.cpp
        parameter_reader.hpp
        Reader.cpp
        Reader.hpp
        SimulatedAnnealing.cpp
        SimulatedAnnealing.hpp
        Solution.cpp
        Solution.hpp)
