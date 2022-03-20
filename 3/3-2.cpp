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
    double squared_error, tmpnormal = 0;

    ofstream of("3-2.csv");
    of << "consumer," << "ratio_of_special," << "expences" << endl;

    // If r is smaller than 9/10, add 1 to the normal version. Otherwise, add 1 to the special version.
    for (int i = 0; i < sizeof(consumer)/sizeof(int); i++) {
        while (special < consumer[i]) {
            r = (rand() + 0.5) / (RAND_MAX + 1.0);
            if (r < (double)9/10) {
                normal++;
                tmpnormal++;
            }
            else {
                special++;
                squared_error += pow((500 * (tmpnormal + 1) - 5000), 2);
                tmpnormal = 0;
            }
        }

        // write to csv file
        of << consumer[i] << ',' << (double)special / (normal + special) << ',' << 500 * (normal + special) / consumer[i] << endl;
        // output variance
        printf("%lf\n", squared_error/consumer[i]);

        // refresh variable
        normal = 0;
        special = 0;
        squared_error = 0;
    }
    return 0;
}