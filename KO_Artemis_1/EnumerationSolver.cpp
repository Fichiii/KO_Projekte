#include "EnumerationSolver.hpp"


vector<int> EnumerationSolver::solve(Instance& toSolve){
    Solution loesung = Solution(toSolve);
    backtracking(loesung,0,toSolve.getNumberOfItems());
    return vector<int> {feasCounter_,optCounter_, optimumValue_};
}

void EnumerationSolver::backtracking(Solution &loesung,const int &index, const int &max) {
    if(index == max)
        {
            if(loesung.isFeasible())
            {
                if(loesung.getValue() == optimumValue_)
                {
                    ++optCounter_;
                }
                    if(loesung.getValue() > optimumValue_)
                    {
                        optimumValue_ = loesung.getValue();
                        optCounter_ = 1;
                    }
                ++feasCounter_;
            }
        }
    else
    {
        loesung.set(index,0);
        backtracking(loesung,index + 1 ,max);
        loesung.set(index, 1);
        backtracking(loesung, index + 1 , max);
    }
}


int EnumerationSolver::optimumValue_ = 0;
int EnumerationSolver::optCounter_ = 0;
int EnumerationSolver::feasCounter_ = 0;
