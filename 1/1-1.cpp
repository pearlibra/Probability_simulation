#include <iostream>
#include <stdlib.h>
#include <random>

using namespace std;

int main() {
    double tmp;
    double sum = 0;

    // setting seed
    srand(2000); 

    //generating random numbers and adding them to "sum" variable
    for (int i=0; i<1000; i++) {
        tmp = (rand() + 0.5) / (RAND_MAX + 1.0);
        printf("%lf\n", tmp);
        sum += tmp;
    }

    //calculating average value and rounding it to the fifth devimal place
    printf("average: %.4lf", round((sum / 1000) * 10000) / 10000);

    return 0;
}