cmake_minimum_required(VERSION 3.16)
project(KO_Artemis_1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(KO_Artemis_1
        main.cpp
        EnumerationSolver.cpp
        Instance.cpp
        Reader.cpp
        Solution.cpp
        EnumerationSolver.hpp
        Solution.hpp
        Reader.hpp
        Instance.hpp
        parameter_reader.hpp
)