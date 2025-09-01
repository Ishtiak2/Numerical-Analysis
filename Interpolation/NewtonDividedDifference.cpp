#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

double newtonInterpolation(int n, double x[], double y[], double p) {
    // Divided difference table
    double dd[100][100];  // adjust size if needed

    // First column is just y values
    
    for (int i = 0; i < n; i++) {
        dd[i][0] = y[i];
    }

    // Fill divided difference table
    
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            dd[i][j] = (dd[i+1][j-1] - dd[i][j-1]) / (x[i+j] - x[i]);
        }
    }

    // Print the divided difference table

    cout << "\nDivided Difference Table:\n";
    cout << fixed << setprecision(6);
    for (int i = 0; i < n; i++) {
        
        cout <<x[i] <<"   ";
        
        for (int j = 0; j < n - i; j++) {
            cout << dd[i][j] <<"    ";
        }
        cout << endl;
    }

    // Apply Newton's formula
    
    double result = dd[0][0];
    double term = 1.0;
    for (int j = 1; j < n; j++) {
        term *= (p - x[j-1]);
        result += dd[0][j] * term;
    }

    return result;
}

int main() {
    int n;
    cout << "Enter number of data points: ";
    cin >> n;

    double x[100], y[100];
    cout << "Enter x values: ";
    for (int i = 0; i < n; i++) cin >> x[i];
    cout << "Enter y values: ";
    for (int i = 0; i < n; i++) cin >> y[i];

    double p;
    cout << "Enter the point to interpolate: ";
    cin >> p;

    double ans = newtonInterpolation(n, x, y, p);
    cout << "\nInterpolated value at x = " << p << " is " << ans << endl;

    return 0;
}
