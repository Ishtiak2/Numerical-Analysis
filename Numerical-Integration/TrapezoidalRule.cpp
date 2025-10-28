#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double x[1000];

double func(double y) {
    return 1.0 / y;  // Example: f(x) = 1/x
}

double trapezoidalRule(double a, double b, int n) {
    double h = (b - a) / n;

    // Generate x values
    x[0] = a;
    for(int i = 1; i <= n; i++) {
        x[i] = x[i - 1] + h;
    }

    // Applying the trapezoidal formula variant:
    // h * [ (f(x0) + f(xn))/2 + sum(f(x1..xn-1)) ]
    double sum = (func(x[0]) + func(x[n])) / 2.0;

    for(int i = 1; i < n; i++) {
        sum += func(x[i]);
    }

    return h * sum;
}

int main() {
    double a, b;
    int n;

    cout << "Enter lower limit (a): ";
    cin >> a;
    cout << "Enter upper limit (b): ";
    cin >> b;
    cout << "Enter number of subintervals (n): ";
    cin >> n;

    
    double ans = trapezoidalRule(a, b, n);

    cout << "Numerical integration using Trapezoidal Rule: " << fixed << setprecision(6) << ans << endl;

    return 0;
}
