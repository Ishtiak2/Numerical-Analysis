#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

double arr[25][25]; // Augmented matrix (1-based)
double x[25];       // Solution vector (1-based)

void gaussElimination(int n, int m) {

    int prow = 1;
    int pcol = 1;

    while (pcol <= m && prow <= n) {

        // Find pivot row
        int pivot = prow;
        for (int i = prow + 1; i <= n; i++) {
            if (fabs(arr[i][pcol]) > fabs(arr[pivot][pcol])) {
                pivot = i;
            }
        }

        // If pivot is zero, move to next column
        if (fabs(arr[pivot][pcol]) < 1e-9) {
            pcol++;
            continue;
        }

        // Swap pivot row to current position
        if (pivot != prow) {
            for (int j = 1; j <= m + 1; j++) {
                swap(arr[pivot][j], arr[prow][j]);
            }
        }

        // Eliminate rows below pivot
        for (int i = prow + 1; i <= n; i++) {
            double factor = arr[i][pcol] / arr[prow][pcol];
            for (int j = pcol; j <= m + 1; j++) {
                arr[i][j] -= factor * arr[prow][j];
            }
        }

        prow++;
        pcol++;
    }

    // Back substitution
    for (int i = n; i >= 1; i--) {

        if (fabs(arr[i][i]) < 1e-9) {
            cout << "No unique solution exists!" << endl;
            return;
        }

        x[i] = arr[i][m + 1];

        for (int j = i + 1; j <= m; j++) {
            x[i] -= arr[i][j] * x[j];
        }

        x[i] /= arr[i][i];
    }
}

int main() {
    int n = 3;
    int m = 3;

    cout << "Enter augmented matrix (1-based):" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m + 1; j++) {
            cin >> arr[i][j];
        }
    }

    gaussElimination(n, m);

    cout << "\nSolution:\n";
    for (int i = 1; i <= n; i++) {
        cout << "x[" << i << "] = " << fixed 
             << setprecision(5) << x[i] << endl;
    }

    return 0;
}
