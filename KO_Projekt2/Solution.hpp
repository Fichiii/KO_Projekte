#pragma once

#include <sstream>
#include <string>
#include <vector>

#include "Instance.hpp"

/**
 * 
 * Class that represents a Solution of the binary knapsack problem as a bit vector (vector with only 0/1-entries).
 * 
 */
class Solution {

private:

    // The corresponding instance
    const Instance& instance;

    // Vector representing how often is each item is used
    std::vector<int> sol;

    // The solution's objective value
    int solValue;

    // The solution's total weight
    int solWeight;

public:
    /**
     * Default constructor, sets the instance and initializes values
     * 
     * @param instance the instance for that this is a Solution of
     */
    explicit Solution(const Instance &instance);

    /**
     * Copy a solution (copy constructor)
     * 
     * @param solution the solution to copy
     */
    Solution(const Solution &solution);

    /**
     * Destructor
     */
    ~Solution();

    /**
     * Returns the instance
     */
    const Instance &getInstance() const;

    /**
     * Assign a quantity to an item
     *
     * @param item The index of the item
     * @param quantity The quantity to be assigned, has to be 0 or 1
     *
     */
    void set(int item, int quantity);

    /**
     * Get the quantity of an item, i.e. if its packed (1) or not packed (0)
     *
     * @param item The index of the item
     *
     * @return The quantity of the item
     */
    int get(int item) const;


    /**
     * Get the solution value
     *
     * @return The Value of the solution
     */
    int getValue() const;

    /**
     * Get the solution weight
     *
     * @return The weight of the solution
     */
    int getWeight() const;

    /**
     * Check if the solution is feasible
     *
     * @return Boolean with the value 1 if the solution is feasible and 0 otherwise
     */
    bool isFeasible() const;

};
