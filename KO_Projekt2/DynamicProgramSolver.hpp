#pragma once

#include "Instance.hpp"
#include "Solution.hpp"

#include <vector>
#include <iostream>

using namespace std;

/**
 * Solves Knapsack by using dynamic programming
 */
class DynamicProgramSolver {

    public:
    /**
     * solve fills the dynamic programming matrix
     * @param toSolve The instance to solve
     * @return returns the optimal solution with help from find_solution
     */
    static Solution solve(const Instance& toSolve);

    /**
     * search the right path by going the matrix backwards
     * @param toSolve The instance to solve
     * @param matrix The filled matrix
     * @return returns the optimal solution for the instance
     */
    static Solution find_solution(const Instance &toSolve,const vector<vector<int>> &matrix);
};
