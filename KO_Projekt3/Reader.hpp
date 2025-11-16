#pragma once

#include <string>
#include <iostream>
#include "Instance.hpp"

using namespace std;

/**
 * A reader for instances for the knapsack problem.
 */
class Reader {

public:

    /**
     * Read knapsack instance from given file.
     *
     * @param filename The filename of the file to read
     *
     * @return The instance
     */
    static Instance readInstanceFromFile(const string& filename);

    /**
     * Read knapsack instance from command args (in the form of param W c1 w1 c2 w2 ... cn wn).
     *
     * @param input_vector with the args (param W c1 w1 c2 w2 ... cn wn)
     *
     * @return The instance
     */
    static Instance readInstanceFromArgs(const vector<string>& input_vector);

    /**
     *
     * Print the usage of this program and exit (used if wrong input has been detected).
     *
     */
    static void printUsageAndExit();
};

