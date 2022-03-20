#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;

int main() {
    srand((unsigned)time(NULL));
    int consumer = 1000;
    int normal = 0, special = 0;
    double r;
    ofstream of("3-a.csv");
    of << "ratio_of_special," << "average_consumer's_side_cost," << "our_profit" << endl;

    for (int i = 1; i < 10; i++) {
        while (special < consumer) {
            r = (rand() + 0.5) / (RAND_MAX + 1.0);
            if (r < (double)i / 10) {
                special++;
            }
            else {
                normal++;
            }
        }
        // write to csv file.
        of << (double)i / 10 << ',' << 500 * (normal + special) / consumer << ',' << 20 * (normal + special) << endl;

        // refresh variable
        normal = 0;
        special = 0;
    }
    return 0;
}