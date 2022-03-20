#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
using namespace std;

int main() {
    double select;
    int n = 3000;
    ofstream of("hawaii.csv");

    // 'a' is the number of times you win without changing the choice.
    // 'b' is the number of times you win by changing the choice.
    int a = 0, b = 0;

    // Setting label
    of << "試行回数" << "," << "変えないで当選する確率" << "," << "変えて当選する確率" << "\n";

    // Set the current time as seed
    srand((unsigned)time(NULL));
    

    for (int i=0; i<n; i++) {
        select = (rand() + 0.5) / (RAND_MAX + 1.0);

        /* If the random number is less than 1/3, add 1 
        to the number of times you win without changing your choice. */
        if (select < (double)1/3) {
            a++;
        } 

        // Otherwise, add 1 to the number of times you win by changing your choice.
        else if (select < (double)2/3) {
            b++;
        }
        else {
            b++;
        }

        // Write the result to a csv file every 10 times.
        if (i % 10 == 9) {
            of << i+1 << "," << (double)a/(i+1) << "," << (double)b/(i+1) << "\n";
        }
    }
    printf("箱の選択を変えないで当たる確率は:%lf\n", (double)a/n);
    printf("箱の選択を変えて当たる確率は:%lf", (double)b/n);
    
    return 0;
}    