#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

// Function definition: f(x) = 4x^2 + 3x - 3
double f(double x) {
    return 4 * x * x + 3 * x - 3;
}

void improvedBisection(double lowerBound, double upperBound, double stepSize, double tolerance) {
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
        return;
    }

    double c;
    int iteration = 0;

    cout << "Improved Bisection Method" << endl;
    cout << "Auto-detected interval: [" << a << ", " << b << "]" << endl;

    while ((b - a) >= tolerance) {
        c = (a + b) / 2;
        iteration++;

        if (fabs(f(c)) < tolerance)
            break; // stop if f(c) is very close to 0

        if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;
        
        cout <<"a = " <<a <<"   b = " <<b << "  c = " << c << endl;

    }

    cout << "Approximate root: " << c << endl;
    cout << "Iterations: " << iteration << endl;
}

int main() {
    double lowerBound = 0;
    double upperBound = 1;
    double stepSize = 0.1;
    double tolerance = 1e-6;

    cout << fixed << setprecision(6);

    improvedBisection(lowerBound, upperBound, stepSize, tolerance);

    return 0;
}
