#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

int main() {
    double x, y;
    double n = 1000;
    double r = 1;
    ofstream qc_of("quarter_circle.csv");
    ofstream ratio_of("ratio.csv");

    // The number of times a dot fits inside the circle
    double in_circle;

    // Setting seed
    srand(2000);
    
    // Setting labels
    qc_of << "x(x^2 + y^2 < 1)" << "," << "x(x^2 + y^2 >= 1)" << "," << "y(x^2 + y^2 < 1)" << "," << "y(x^2 + y^2 >= 1)" << "\n";
    ratio_of << "n" << "," << "ratio" << "\n";
    
    // Generate a point by random numbers and try to see if it fits in the circle.
    for (int i=1; i<=n; i++) {
        x = (rand() + 0.5) / (RAND_MAX + 1.0);
        y = (rand() + 0.5) / (RAND_MAX + 1.0);

        // Write to the first and third columns of the csv file when a point fits in the circle.
        if (x*x + y*y < r) {
            in_circle++;
            qc_of << x << ",," << y << ",," << "\n";
        }

        // Otherwise, write to the second and fourth columns
        else { 
            qc_of << "," << x << ",," << y << "\n";
        }
        // Write the calculated π
        ratio_of << i << "," << round(((4 * in_circle / i) * 10000)) / 10000 << "\n";
    }

    printf("pi = %.4lf", round(((4 * in_circle / n) * 10000)) / 10000);

    return 0;
}