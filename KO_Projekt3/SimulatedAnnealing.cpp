#include "SimulatedAnnealing.hpp"

//TODO: Mache schöner
//TODO: Füge andere Startlösung hinzu
//TODO: Teste in Artemis
//TODO: Maybe effizienter machen


//Setze Startlösung auf 0
void SimulatedAnnealing::generate_firt_solution(Solution &solution, Instance& toSolve){
    for(int i = 0; i < toSolve.n(); i++){
        solution.set(i,0);
    }
}
//Generiere random Solution in dem 1 Bit gefliped wird
Solution SimulatedAnnealing::generate_random_solution(Solution &solution, Instance& toSolve){
    Solution new_solution = solution;

    int random_num = random_int(toSolve);

    if(solution.get(random_num) == 0){
        new_solution.set(random_num, 1);
    }
    else{
        new_solution.set(random_num, 0);
    }
    return new_solution;
}

//Generiere Zahl zwischen 0 und n-1
int random_int(Instance &toSolve){

    static mt19937 engine(random_device{}());

    uniform_int_distribution<> dist(0, toSolve.n() -1);

    return dist(engine);
}

//Generiere 0 oder 1
double random01(){

    static mt19937 engine(random_device{}());

    uniform_real_distribution<double> dist(0, 1);

    return dist(engine);
}

void SimulatedAnnealing::print_start_solution(Solution &solution){
    cout << "Startloesung mit Zielfunktionswert: " << solution.getValue() << '\n';
    for(int i = 0; i < solution.getInstance().getNumberOfItems(); i++){
        cout << solution.get(i) << ' ';
    }
    cout << '\n';
}

void SimulatedAnnealing::print_best_solution(Solution &solution){
    cout << "beste gefundene Loesung mit Zielfunktionswert: " << solution.getValue() << '\n';
    for(int i = 0; i < solution.getInstance().getNumberOfItems(); i++){
        cout << solution.get(i) << ' ';
    }
    cout << '\n';
}

void SimulatedAnnealing::solve(Instance& toSolve, int timelimit, int iterationlimit, double starttemperature, double factor) {
    Solution solution = Solution(toSolve);

    generate_firt_solution(solution, toSolve);

    print_start_solution(solution);

    Solution best_solution = solution;

    int counter_to_cool = 10 * toSolve.n();

    double temperatur = starttemperature;

    int best_value = best_solution.getValue();

    bool stop_criteria = false;

    int counter = 0;

    int cooling_counter = 0;

    const chrono::seconds time_limit(timelimit);

    auto start_time = chrono::steady_clock::now();

    auto deadline = start_time + time_limit;

    while(!stop_criteria){
        Solution new_solution = generate_random_solution(solution, toSolve);

        int curr_value = solution.getValue();
        int rand_weight = new_solution.getWeight();
        int rand_value= solution.getValue();

        double fraction = (rand_value - curr_value)/temperatur;

        if (rand_weight <= toSolve.getCapacity()) {
            if(rand_value >= curr_value || random01() < exp(fraction)){
                solution = new_solution;

                if(rand_value >= best_value){
                    best_solution = new_solution;
                    best_value = rand_value;
                }
            }
        }

            counter++;
            cooling_counter++;

            if(cooling_counter == counter_to_cool){
                temperatur *= factor;
                cooling_counter = 0;
            }

            if(counter == iterationlimit || timelimit > 0 && chrono::steady_clock::now() >= deadline){
                stop_criteria = true;
            }
        }


    print_best_solution(best_solution);
}