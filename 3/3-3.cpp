#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
    srand((unsigned)time(NULL));
    int consumer[9] = {10, 50, 100, 500, 1000, 5000, 10000, 50000, 100000};
    int normal = 0, special = 0;
    double r;
    int i,j,k = 0;
    double squared_error = 0;
    ofstream of("3-3.csv");
    of << "consumer," << "ratio_of_special," << "expences" << endl;

    // If r is smaller than 1/2, add 1 to the normal version. Otherwise, add 1 to the special version.
    // There is a limit of 4 times this experiment.
    for (i=0; i < sizeof(consumer)/sizeof(int); i++) {
        for(j=0; j<consumer[i]; j++) {
            k = 0;
            while (k < 4) {
                r = (rand() + 0.5) / (RAND_MAX + 1.0);
                if (r < (double)1/2) {
                    normal++;
                    if (k == 3) {
                        squared_error += pow(500 * (k+1) - (double)500 * 15/8, 2);
                    }
                }
                else {
                    special++;
                    squared_error += pow(500 * (k+1) - (double)500 * 15/8, 2);
                    break;
                }
                k++;
            }
        }

        // write to csv file
        of << consumer[i] << ',' << (double)special / (normal + special) << ',' << (double)500 * (normal + special) / consumer[i] << endl;
        // output variance
        printf("%lf\n", squared_error/consumer[i]);

        // refresh variable
        squared_error = 0;
        normal = 0;
        special = 0;
    }
    return 0;
}