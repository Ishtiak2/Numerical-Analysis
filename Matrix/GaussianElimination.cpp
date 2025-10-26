#include <bits/stdc++.h>
#include<iomanip>

using namespace std;

double arr[20][20]; // Augmented matrix
double x[20];       // Solution vector

void gaussElimination(int n, int m) {
    int prow = 0, pcol = 0;

    while (pcol < m && prow < n) {
        // Find pivot row (largest absolute value)
        int pivot = prow;
        for (int i = prow + 1; i < n; i++) {
            if (fabs(arr[i][pcol]) > fabs(arr[pivot][pcol])) {
                pivot = i;
            }
        }

        // If pivot element is zero, skip this column
        if (fabs(arr[pivot][pcol]) < 1e-9) {
            pcol++;
            continue;
        }

        // Swap current row with pivot row
        if (pivot != prow) {
            for (int i = 0; i <= m; i++) {
                swap(arr[pivot][i], arr[prow][i]);
            }
        }

        // Eliminate below pivot
        for (int i = prow + 1; i < n; i++) {
            double factor = arr[i][pcol] / arr[prow][pcol];
            for (int j = pcol; j <= m; j++) {
                arr[i][j] -= factor * arr[prow][j];
            }
        }

        prow++;
        pcol++;
    }

    // Back Substitution
    for (int i = n - 1; i >= 0; i--) {
        x[i] = arr[i][m]; // Start with constant term
        for (int j = i + 1; j < m; j++) {
            x[i] -= arr[i][j] * x[j];
        }
        x[i] /= arr[i][i]; // Divide by pivot
    }
}

int main() {
    int n = 3; // Number of equations
    int m = 3; // Number of variables

    cout << "Enter augmented matrix (each row: a b c | d):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            cin >> arr[i][j];
        }
    }

    gaussElimination(n, m);

    cout << "\nSolution:\n";
    for (int i = 0; i < n; i++) {
        cout << "x[" << i << "] = " << fixed << setprecision(5) << x[i] << endl;
    }

    return 0;
}
