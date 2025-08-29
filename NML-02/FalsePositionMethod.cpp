#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

// Function: f(x) = 4x^2 + 3x - 3
double f(double x) {
    return 4 * x * x + 3 * x - 3;
}

void regularFalsePosition(double a, double b, double tolerance, int maxIterations = 1000) {
    
    if (f(a) * f(b) >= 0) {
        cout << "Invalid interval: f(a) and f(b) must have opposite signs.\n";
        return;
    }

    double c;
    int iteration = 0;

    cout << "Regular False Position Method" << endl;
    cout << "Initial interval: [" << a << ", " << b << "]\n";

    while ((b - a) >= tolerance && iteration < maxIterations) {
        
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));  // Regula Falsi formula
        iteration++;

        if (f(c) == 0.0) {
            break; // Exact root found
        }

        if (f(c) * f(a) < 0)
            b = c;
        
        else
            a = c;
        
        cout << fixed << setprecision(6);
        cout <<"a = " <<a <<" b = " <<b << " c = " << c << endl;
    }

    cout << fixed << setprecision(6);
    cout << "Approximate root: " << c << endl;
    cout << "Iterations: " << iteration << endl;
}

int main() {
    double a = 0;
    double b = 1;
    double tolerance = 1e-6;

    regularFalsePosition(a, b, tolerance);

    return 0;
}
