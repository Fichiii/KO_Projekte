#include "Solution.hpp"

Solution::Solution(const Instance &instance)
        : instance(instance)
        , sol(std::vector<int>(instance.getNumberOfItems(), 0))
        , solValue(0)
        , solWeight(0) {}

Solution::Solution(const Solution &solution)
        : Solution(solution.getInstance())
{
    for (auto i = 0; i < instance.getNumberOfItems(); i++)
    {
        set(i, solution.get(i));
    }
}

Solution::~Solution() = default;

const Instance& Solution::getInstance() const { 
    return instance; 
}

void Solution::set(int item, int quantity) {
    if (!(quantity == 0 || quantity == 1)) {
        std::exit(EXIT_FAILURE);
    }
    solValue += (quantity - sol.at(item)) * instance.getValue(item);
    solWeight += (quantity - sol.at(item)) * instance.getWeight(item);
    sol[item] = quantity;
}

int Solution::get(int item) const {
     return sol[item]; 
}

int Solution::getValue() const {
     return solValue; 
}
int Solution::getWeight() const {
     return solWeight; 
}

bool Solution::isFeasible() const {
     return getWeight() <= instance.getCapacity();
}
