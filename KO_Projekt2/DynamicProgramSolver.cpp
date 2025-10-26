#include "DynamicProgramSolver.hpp"

//Verfolge den Weg zurück für die Lösungsinszanz
Solution DynamicProgramSolver::find_solution(const Instance &toSolve, const vector<vector<int>> &matrix) {
    Solution solution = Solution(toSolve);
    int capacity = toSolve.getCapacity();
    const int n = toSolve.getNumberOfItems();

    //Wenn über dem Matrixeintrag der selbe Wert steht, setze Item auf 0. Sonst 1
    for (int i = n; 0 < i; i--)
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


//Fülle Matrix
Solution DynamicProgramSolver::solve(const Instance& toSolve){
    const int n = toSolve.getNumberOfItems();
    const int W = toSolve.getCapacity();

    //Initialisierung
    vector<vector<int>> matrix(n + 1, vector<int>(W + 1,0));

    //Main Loop
    for (int j = 1; j <= n; j++)
    {
        const int weight_j = toSolve.getWeight(j - 1);
        const int value_j = toSolve.getValue(j - 1);

        for (int k = 1; k <= W; k++)
        {
            if (k - weight_j >= 0 && matrix[j-1][k] < matrix[j-1][k - weight_j] + value_j)
            {
                matrix[j][k] = matrix[j-1][k - weight_j] + value_j;
            }
            else
            {
                matrix[j][k] = matrix[j-1][k];
            }
        }
    }
    //Ergebnis holen
    return find_solution(toSolve, matrix);
}


