#pragma once

#include "Instance.hpp"
#include "Solution.hpp"

#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

// TODO: comment this class with Doxygen (and delete this comment)
class EnumerationSolver {
    static int optimumValue_;
    static int optCounter_;
    static int feasCounter_;

public:

    static vector<int> solve(Instance& toSolve);
    static void backtracking(Solution &loesung,const int &index,const int &max);
};