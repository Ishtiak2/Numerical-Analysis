#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double func(double x) {
    // Example: f(x) = 1/x
    return 1.0 / x;
}

double simpsonOneThird(double a, double b, int n) {
    
    if(n % 2 != 0) {
        cout << "Error: n must be even for Simpson's 1/3 Rule." << endl;
        return INFINITY;
    }

    double h = (b - a) / n;
    double sum = func(a) + func(b);

    for(int i = 1; i < n; i++) {
        
        double x = a + i * h;
        
        if(i % 2 == 0) {
            sum += 2.0 * func(x);  // even indices
        }
        
        else {
            sum += 4.0 * func(x);  // odd indices
        }
    }

    return (h / 3.0) * sum;
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

    double result = simpsonOneThird(a, b, n);
    cout << "Numerical integration using Simpson 1/3 Rule: " << fixed << setprecision(6) << result << endl;

    return 0;
}
