/*
 * Autor: Fritz Bökler (November 2023), Edited by Nick Kloster (April 2025)
 *
 * Diese Header Datei enthält nur die Funktion
 * stringstream input_to_vector(int argc, char** args).
 *
 * Diese ermöglicht die Übergabe der Parameter einer main-Funktion
 * mit Kommandozeilenparametern
 * int main(int argc, char** argv)
 * direkt an einen vector.
 *
 * Benutzung: Um mit den Kommandozeilen-Parametern zu arbeiten, einfach statt der
 * int main()
 * Funktion, die Funktion
 * int main(int argc, char** argv)
 * definieren und darin mit dem Aufruf
 * vector<string> input_vector = input_to_vector(argc, argv);
 * einen vector<string> input_vector erzeugen, der die Kommandozeilen-Parameter enthält.
 *
 */
#pragma once
#include <sstream>
#include <vector>
#include <string>

inline std::vector<std::string> input_to_vector(int argc, char** argv) {
    std::vector<std::string> vec;
    std::stringstream string_stream;
    for(int i = 1; i < argc; ++i)
    {
        string_stream << argv[i] << ' ';
    }
    std::string a;
    while(string_stream >> a) {
        vec.push_back(a);
    }
    return vec;
}


