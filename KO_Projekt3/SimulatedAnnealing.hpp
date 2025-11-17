#pragma once

#include "Instance.hpp"
#include "Solution.hpp"

#include <vector>
#include <iostream>
#include <cmath>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;

// TODO: comment this class with Doxygen (and delete this comment)
class SimulatedAnnealing {

    public:
        static void solve(Instance& toSolve, int timelimit, int iterationlimit, double starttemperature, double factor);
        static void generate_first_solution(Solution &solution, Instance& toSolve);
        static Solution generate_random_solution(Solution &solution, Instance& toSolve);
        static void print_start_solution(Solution &solution);
        static void print_best_solution(Solution &solution, const int &counter);
};

int random_int(Instance &toSolve);
double random01();