#include <iostream>
#include <stdlib.h>
#include <random>

using namespace std;

int main() {
    double tmp;
    double face = 0;
    double back = 0;

    // setting seed
    srand(2000);

    // generating random numbers and logging face or back
    for (int i=0; i<1000; i++) {

        // generating random numbers in the range(0,1)
        tmp = (rand() + 0.5) / (RAND_MAX + 1.0);

        // If a random number is more than 1/2, add 1 to "face" variable
        if (round(tmp*1000)/1000 >= (double)1/2) {
            face++;
        } 
        // Otherwaise, add 1 to "back" variable
        else {
            back++;
        }
    }
    // Output the ratio of face and back
    printf("face: %.4lf\n", face / 1000);
    printf("back: %.4lf\n", back / 1000);
    
    return 0;
}