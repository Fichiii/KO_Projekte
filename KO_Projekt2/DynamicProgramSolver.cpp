#include "DynamicProgramSolver.hpp"


Solution DynamicProgramSolver::find_path(const Instance &toSolve, const vector<vector<int>> &matrix) {
    Solution solution = Solution(toSolve);
    int capacity = toSolve.getCapacity();

    for (int i = toSolve.getNumberOfItems(); 0 < i; i--)
    {
        if (matrix[i][capacity] == matrix[i - 1][capacity]) { solution.set(i - 1,0); }
        else
        {
            capacity = capacity - toSolve.getWeight(i - 1);
            solution.set(i - 1,1);
        }
    }
    return solution;
}

Solution DynamicProgramSolver::solve(const Instance& toSolve){

    //Initialisierung
    vector<vector<int>> matrix(toSolve.getNumberOfItems() + 1, vector<int>(toSolve.getCapacity() + 1,0));

    //Main Loop
    for (int j = 1; j <= toSolve.getNumberOfItems(); j++)
    {
        for (int k = 1; k <= toSolve.getCapacity(); k++)
        {

            if (k - toSolve.getWeight(j - 1) > 0 && matrix[j-1][k] < matrix[j-1][k - toSolve.getWeight(j - 1)] + toSolve.getValue(j - 1))
            {
                matrix[j][k] = matrix[j-1][k - toSolve.getWeight(j - 1)] + toSolve.getValue(j - 1);
            }
            else
            {
                matrix[j][k] = matrix[j-1][k];
            }
        }
    }
    //Ergebnis holen
    return find_path(toSolve, matrix);
}


