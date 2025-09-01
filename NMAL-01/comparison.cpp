#include<bits/stdc++.h>
#include <iomanip>
using namespace std;

double f(double x) {
    return 4 * x * x + 3 * x - 3;
}

int bisection(double a, double b, double tolerance) {
    if (f(a) * f(b) >= 0) {
        cout << "Invalid interval: f(a) and f(b) must have opposite signs.\n";
        return -1000;
    }

    double c;
    int iteration = 0;


    while ((b - a) >= tolerance) {
        c = (a + b) / 2;
        iteration++;

        if (fabs(f(c)) < tolerance)
            break; // stop if f(c) is very close to 0

        if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;

    }

    cout << fixed << setprecision(6);
    cout << "Approximate root in traditional bisection: " << c <<"  ";
    cout << "iterations: " << iteration << endl;
    return iteration;
}

int improvedBisection(double lowerBound, double upperBound, double stepSize, double tolerance) {
    double a = 0, b = 0;
    bool found = false;

    for (double x = lowerBound; x < upperBound; x += stepSize) {
        
        if (f(x) * f(x + stepSize) < 0) {
            a = x;
            b = x + stepSize;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "No valid interval found in [" << lowerBound << ", " << upperBound << "]" << endl;
        return -1000;
    }

    double c;
    int iteration = 0;

    while ((b - a) >= tolerance) {
        c = (a + b) / 2;
        iteration++;

        if (fabs(f(c)) < tolerance)
            break; // stop if f(c) is very close to 0

        if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;
        
    }

    cout << fixed << setprecision(6);
    cout << "Approximate root in improved bisection method: " << c <<" ";
    cout << "iterations: " << iteration << endl;

    return iteration;
}

int main() {
    double a = 0;            
    double b = 1;             
    double tolerance = 1e-6;
    double stepSize = 0.1;

    int iter1 = bisection(a, b, tolerance);
    int iter2 = improvedBisection(a,b,stepSize,tolerance);

    cout << "Traditional Bisection Iterations: " << iter1 <<endl;
    cout << "Improved Bisection Iterations: " <<iter2 << endl;

    return 0;
}
