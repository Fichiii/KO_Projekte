cmake_minimum_required(VERSION 4.0)
project(P1_Code)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(P1_Code
        EnumerationSolver.cpp
        EnumerationSolver.hpp
        Instance.cpp
        Instance.hpp
        main.cpp
        parameter_reader.hpp
        Reader.cpp
        Reader.hpp
        Solution.cpp
        Solution.hpp)
