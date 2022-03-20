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
    double squared_error = 0;
    double tmpnormal = 0;

    ofstream of("3-1.csv");
    of << "consumer," << "ratio_of_special," << "average_expences" << endl;

    // If r is smaller than 1/2, add 1 to the normal version. Otherwise, add 1 to the special version.
    for (int i = 0; i < sizeof(consumer)/sizeof(int); i++) {
        while (special < consumer[i]) {
            r = (rand() + 0.5) / (RAND_MAX + 1.0);
            if (r < (double)1/2) {
                normal++;
                tmpnormal++;
            }
            else {
                special++;
                squared_error = squared_error + pow((500*(tmpnormal+1) - 1000), 2.0);
                tmpnormal = 0;
            }
        }

        // write to csv file
        of << consumer[i] << ',' << (double)special / (normal + special) << ',' << 500 * (normal + special) / consumer[i] << endl;
        // output variance
        cout << squared_error / consumer[i] << endl;

        // refresh variable
        normal = 0;
        special = 0;
        squared_error = 0;
        tmpnormal = 0;
    }

    return 0;
}