#include "Reader.hpp"
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;


Instance Reader::readInstanceFromFile(const string& filename) {
    // Open the input file
    ifstream is(filename);

    // Read in the header
    if (!is) {
        cerr << "Failed to create input reader\n";
        printUsageAndExit();
    }

    // Reads the number n of items in the file
    int n = 0;
    if (!(is >> n)) {
        cerr << "Failed to read n (number of items)\n";
        printUsageAndExit();
    }

    // Create the instance object
    auto instance = Instance(n);
    instance.setFilename(filename);

    // Reads the values and weights of each item from the file and writes them into the instance
    for (int i = 0; i < n; i++) {
        int value = 0;
        int weight = 0;
        if (!(is >> value >> weight)) {
            cerr << "Failed to read value or weight\n";
            printUsageAndExit();
        }
        instance.set(i, value, weight);
    }

    // Reads the capacity value from the file
    int W = 0;
    if (!(is >> W)) {
        cerr << "Failed to read W (capacity of knapsack)\n";
        printUsageAndExit();
    }
    instance.setCapacity(W);

    // Close the input file
    is.close();

    // Return the instance
    return instance;
}

Instance Reader::readInstanceFromArgs(const vector<string>& input_vector) {
    if (input_vector.size() % 2 == 0 || input_vector.size() < 5) { // assumption: no empty instances, i.e. at least 1 item
        cerr << "Not enough command params given, have to be at least 5 (no empty instances!)\n";
        printUsageAndExit();
    }
    //creating Instance from commandline arguments
    int numberOfItems = (input_vector.size()-3)/2;
    Instance instance = Instance(numberOfItems);
    instance.setCapacity(stoi(input_vector[2]));
    int ctr = 0;
    for (int i = 3; i < input_vector.size(); i+=2) {
        int value = (stoi(input_vector[i]));
        int weight = (stoi(input_vector[i+1]));
        instance.set(ctr,value,weight);
        ctr++;
    }
    return instance;  
}

void Reader::printUsageAndExit() {
    cerr << "Wrong formated input! A call looks like\n";
    cerr << "    dat t/f knapsackfile_location OR\n";
    cerr << "    param t/f W c1 w1 c2 w2 ... cn wn\n";
    exit(EXIT_FAILURE);
}
