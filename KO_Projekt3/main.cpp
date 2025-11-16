#include <iostream>
#include <vector>
#include <string>
#include <chrono>

#include "Instance.hpp"
#include "Reader.hpp"
#include "parameter_reader.hpp"
#include "SimulatedAnnealing.hpp"

using namespace std;

int main(int argc, char** argv) {

    vector<string> input_vector = input_to_vector(argc, argv);

    if(input_vector.size() < 6) {
        Reader::printUsageAndExit();
    }

    bool measureRuntime = true;

    int timelim, iters;
    double temp, factor;

    try {
        timelim = std::stoi(input_vector[1]);
        iters   = std::stoi(input_vector[2]);
        temp    = std::stod(input_vector[3]);
        factor  = std::stod(input_vector[4]);
    }
    catch (const std::invalid_argument& e) {
        Reader::printUsageAndExit();
    }

    // input via file
    if (input_vector[0] == "dat") {
        // Read insance from file, exit if error
        Instance instance = Reader::readInstanceFromFile(input_vector[5]);

        // Solve, print solutions and print time taken
        chrono::time_point<std::chrono::high_resolution_clock> start;
        chrono::time_point<std::chrono::high_resolution_clock> end;
        if(measureRuntime)
            start = chrono::high_resolution_clock::now();
        SimulatedAnnealing::solve(instance, timelim, iters, temp, factor);
        if(measureRuntime)
            end = chrono::high_resolution_clock::now();
        

        // extract instancename as only the substring after the last slash
        string instancename = input_vector[5];
        size_t pos = instancename.find_last_of('/');
        if (pos != std::string::npos)
            instancename = instancename.substr(pos + 1); 
        
        // Print time taken
        chrono::duration<double> duration; // runtime in seconds
        if (measureRuntime) {
            duration = end - start;
            cout << "Benoetigte Laufzeit fuers Loesen von " << instancename << ": " << duration.count() << " Sekunden\n";
        }
        
    }

    // input via command line arguments
    else if(input_vector[0] == "param") {
        // Read insance from command line args, exit if error
        Instance instance = Reader::readInstanceFromArgs(input_vector);

        // Solve the instance
        SimulatedAnnealing::solve(instance, timelim, iters, temp, factor);
    }

    // wrong input
    else {
        Reader::printUsageAndExit();
    }

}