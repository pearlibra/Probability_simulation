#include <iostream>
#include <stdlib.h>
#include <random>
#include <fstream>
using namespace std;

int main() {
    double sum = 0;
    double random_num;
    ofstream of("bias.csv");
    of << "試行回数" << "," << "実験値\n";

    // setting seed
    srand(2000);

    /* 
    Using a uniform random number of (0,1), simulate a dice roll 
    with a probability of 1/2 of 1 and a probability of 1/10 of 2 to 6. 
    */
    for (int i = 0; i < 500; i++) {
        random_num = (rand() + 0.5) / (RAND_MAX + 1.0);
        // If the random number random_num is less than 1/2, it is assumed to be 1.
        if (random_num < (double)1/2) {
            sum += 1;
        }
        // Since 2 to 6 have equal probability, change the number every 1/10.
        else if (random_num < (double)6/10) {
            sum += 2;
        }
        else if (random_num < (double)7/10) {
            sum += 3;
        }
        else if (random_num < (double)8/10) {
            sum += 4;
        }
        else if (random_num < (double)9/10) {
            sum += 5;
        }
        else {
            sum += 6;
        }

        // For every 10 dice rolls, write the number of trials and the expected value in "bias.csv".
        if (i % 10 == 9) {
            of << i + 1 << "," << round(sum / (i + 1) * 1000) / 1000 << endl;
        }
    }
    return 0;
}