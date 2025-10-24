cmake_minimum_required(VERSION 4.0)
project(KO_Projekt2)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(KO_Projekt2
        DynamicProgramSolver.cpp
        DynamicProgramSolver.hpp
        Instance.cpp
        Instance.hpp
        main.cpp
        parameter_reader.hpp
        Reader.cpp
        Reader.hpp
        Solution.cpp
        Solution.hpp)
