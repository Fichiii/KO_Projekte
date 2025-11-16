#include "Solution.hpp"

Solution::Solution(Instance &instance)
        : instance(instance)
        , sol(std::vector<int>(instance.getNumberOfItems(), 0))
        , solValue(0)
        , solWeight(0) {}

Solution::Solution(Solution &solution)
        : Solution(solution.getInstance())
{
    for (auto i = 0; i < instance.getNumberOfItems(); i++)
    {
        set(i, solution.get(i));
    }
}

Solution& Solution::operator=(Solution& other) {
    this->instance = other.getInstance();
    for (auto i = 0; i < instance.getNumberOfItems(); i++)
    {
        this->set(i, other.get(i));
    }
    return *this;
}

Solution::~Solution() = default;

Instance& Solution::getInstance() { 
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

int Solution::get(int item) {
     return sol[item]; 
}

int Solution::getValue() {
     return solValue; 
}
int Solution::getWeight() {
     return solWeight; 
}

bool Solution::isFeasible() {
     return getWeight() <= instance.getCapacity();
}
