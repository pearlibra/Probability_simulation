#include <iostream>
#include <stdlib.h>
#include <random>
#include <fstream>
using namespace std;

int main() {
    double sum = 0;
    double random_num;
    ofstream of("simulation.csv");
    of << "試行回数" << "," << "実験値\n";

    // setting seed
    srand(2000);

    // simulate dice rolls using uniform random numbers
    for (int i = 0; i < 500; i++) {
        random_num = (rand() + 0.5) / (RAND_MAX + 1.0);
        if (random_num < (double)1 / 6) {
            sum += 1;
        }
        else if (random_num < (double)2 / 6) {
            sum += 2;
        }
        else if (random_num < (double)3 / 6) {
            sum += 3;
        }
        else if (random_num < (double)4 / 6) {
            sum += 4;
        }
        else if (random_num < (double)5 / 6) {
            sum += 5;
        }
        else {
            sum += 6;
        }
        /* 
        For every 10 dice rolls, output the expected value up to that point
        and write the number of trials and the expected value in "simulation.csv"
        */
        if (i % 10 == 9) {
            printf("%d回目までの試行における期待値は%.3lf\n", i + 1, round(sum / (i + 1) * 1000) / 1000);
            of << i + 1 << "," << round(sum / (i + 1) * 1000) / 1000 << endl;
        }
    }
    return 0;
}