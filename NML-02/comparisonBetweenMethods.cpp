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

        if (f(c) == 0.0) {
            break; // Exact root found
        }

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

int regularFalsePosition(double a, double b, double tolerance) {
    
    if (f(a) * f(b) >= 0) {
        cout << "Invalid interval: f(a) and f(b) must have opposite signs.\n";
        return -1000;
    }

    double c;
    int iteration = 0;

    while ((b - a) >= tolerance) {
        
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));
        iteration++;

        if (f(c) == 0.0) {
            break; // Exact root found
        }

        if (f(c) * f(a) < 0)
            b = c;
        
        else
            a = c;
        
        cout << fixed << setprecision(6);
    }

    cout << fixed << setprecision(6);
    cout << "Approximate root in False Position Method: " << c <<"  iterations: " << iteration << endl;
    return iteration;
}

int main() {
    double a = 0;            
    double b = 1;             
    double tolerance = 1e-6;
    double stepSize = 0.1;

    int iter1 = bisection(a, b, tolerance);
    int iter2 = regularFalsePosition(a,b,tolerance);

    cout << "Traditional Bisection Iterations: " << iter1 <<endl;
    cout << "False Position Method Iterations: " <<iter2 << endl;

    return 0;
}
