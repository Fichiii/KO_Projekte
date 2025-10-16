#include <iostream>
#include <vector>
#include <string>
#include <chrono>

#include "Instance.hpp"
#include "Reader.hpp"
#include "parameter_reader.hpp"
#include "EnumerationSolver.hpp"

using namespace std;

int main(int argc, char** argv) {

    vector<string> input_vector = input_to_vector(argc, argv);

    if(input_vector.size() < 3) {
        Reader::printUsageAndExit();
    }

    bool measureRuntime = (input_vector[1] == "t");

    // input via file
    if (input_vector[0] == "dat") {
        // Read instance from file, exit if error
        Instance instance = Reader::readInstanceFromFile(input_vector[2]);

        // Measure time and/or solve
        chrono::time_point<std::chrono::high_resolution_clock> start;
        chrono::time_point<std::chrono::high_resolution_clock> end;
        if(measureRuntime)
            start = chrono::high_resolution_clock::now();
        vector<int> result = EnumerationSolver::solve(instance);
        if(measureRuntime)
            end = chrono::high_resolution_clock::now();
        

        // extract instancename as only the substring after the last slash
        string instancename = input_vector[2];
        size_t pos = instancename.find_last_of('/');
        if (pos != std::string::npos)
            instancename = instancename.substr(pos + 1); 
        
        // Print solution
        chrono::duration<double> duration; // runtime in seconds
        if (measureRuntime) {
            duration = end - start;
            cout << "Benoetigte Laufzeit fuers Loesen von " << instancename << ": " << duration.count() << " Sekunden\n";
        }
        cout << instancename << ": Anzahl zulaessig: " << result[0] << ", Anzahl optimal: " << result[1] << ", Optimaler Zielfunktionswert: " << result[2] << "\n";
        
    }

    // input via command line arguments
    else if(input_vector[0] == "param") {
        // Read insance from command line args, exit if error
        Instance instance = Reader::readInstanceFromArgs(input_vector);

        // Solve the instance
        vector<int> result = EnumerationSolver::solve(instance);

        // Print solution
        cout << "Anzahl zulaessig: "<< result[0] << ", Anzahl optimal: " << result[1] << ", Optimaler Zielfunktionswert: " << result[2] << "\n";
    }

    // wrong input
    else {
        Reader::printUsageAndExit();
    }

}