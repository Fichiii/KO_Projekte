#pragma once

#include "Instance.hpp"
#include "Solution.hpp"

#include <vector>
#include <iostream>

using namespace std;

// TODO: comment this class with Doxygen (and delete this comment)
class DynamicProgramSolver {

    public:
        static Solution solve(const Instance& toSolve);
        static Solution find_solution(const Instance &toSolve,const vector<vector<int>> &matrix);
};
