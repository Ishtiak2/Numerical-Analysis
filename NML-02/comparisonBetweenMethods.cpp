#include<bits/stdc++.h>
#include <iomanip>
using namespace std;

const double x_true = ((-3 + sqrt(57.0)) / 8.0);

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
    double truePercentRelativeError;

    while ((b - a) >= tolerance) {
        c = (a + b) / 2;
        iteration++;
        truePercentRelativeError = fabs((x_true - c) / x_true) * 100;
        
    
        cout << "c = " << c << ", TPRE = " << truePercentRelativeError <<"%" <<endl;

        if (f(c) == 0.0) {
            break; // Exact root found
        }

        if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;
        
        
    }


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
    double truePercentRelativeError;

    while ((b - a) >= tolerance) {
        
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));
        iteration++;
        
        truePercentRelativeError = fabs((x_true - c) / x_true) * 100;
    
        cout << "c = " << c << ", TPRE = " << truePercentRelativeError <<"%" << endl;

        if (f(c) == 0.0) {
            break; // Exact root found
        }

        if (f(c) * f(a) < 0)
            b = c;
        
        else
            a = c;
        
    
    }


    cout << "Approximate root in False Position Method: " << c <<"  iterations: " << iteration << endl;
    return iteration;
}

int main() {
    double a = 0;            
    double b = 1;             
    double tolerance = 1e-4;
    double stepSize = 0.1;

    //cout << fixed << setprecision(6);

    int iter1 = bisection(a, b, tolerance);
    int iter2 = regularFalsePosition(a,b,tolerance);


    return 0;
}
