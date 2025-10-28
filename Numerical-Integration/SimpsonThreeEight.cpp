#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double func(double x) {
    // Example: f(x) = 1/x
    return 1.0 / x;
}

double simpsonThreeEight(double a, double b, int n) {
    
    if(n % 3 != 0) {
        cout << "Error: n must be a multiple of 3 for Simpson's 3/8 Rule." << endl;
        return INFINITY;
    }

    double h = (b - a) / n;
    double sum = func(a) + func(b);

    for(int i = 1; i < n; i++) {
        
        double x = a + i * h;
        
        if(i % 3 == 0) {
            sum += 2.0 * func(x);  // multiples of 3
        }
        
        else {
            sum += 3.0 * func(x);  // others
        }
    }

    return (3.0 * h / 8.0) * sum;
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

    double result = simpsonThreeEight(a, b, n);
    cout << "Numerical integration using Simpson 3/8 Rule: " << fixed << setprecision(6) << result << endl;

    return 0;
}
