#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

double arr[25][25]; // Augmented matrix (1-based)
double x[25];       // Solution vector (1-based)

void gaussJordan(int n, int m) {
    int prow = 1, pcol = 1;

    while (prow <= n && pcol <= m) {

        // Partial pivoting: find row with largest absolute value in this column
        int pivot = prow;
        for (int i = prow + 1; i <= n; i++) {
            if (fabs(arr[i][pcol]) > fabs(arr[pivot][pcol])) {
                pivot = i;
            }
        }

        // Swap pivot row with current row
        for (int j = 1; j <= m + 1; j++) {
            swap(arr[prow][j], arr[pivot][j]);
        }

        // Check for zero pivot (singular or no unique solution)
        if (fabs(arr[prow][pcol]) < 1e-9) {
            cout << "Mathematical Error: Singular Matrix or No Unique Solution!\n";
            exit(0);
        }

        // Make pivot = 1
        double pivotVal = arr[prow][pcol];
        for (int j = 1; j <= m + 1; j++) {
            arr[prow][j] /= pivotVal;
        }

        // Eliminate all other rows in this column
        for (int i = 1; i <= n; i++) {
            if (i != prow) {
                double factor = arr[i][pcol];
                for (int j = 1; j <= m + 1; j++) {
                    arr[i][j] -= factor * arr[prow][j];
                }
            }
        }

        prow++;
        pcol++;
    }

    // Store solution
    for (int i = 1; i <= n; i++) {
        x[i] = arr[i][m+1];
    }
}

int main() {
    int n, m;
    cout << "Enter number of equations and unknowns: ";
    cin >> n >> m;

    cout << "Enter augmented matrix (1-based):\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m + 1; j++) {
            cin >> arr[i][j];
        }
    }

    gaussJordan(n, m);

    cout << "\nSolution:\n";
    for (int i = 1; i <= n; i++) {
        cout << "x[" << i << "] = " << fixed << setprecision(5) << x[i] << endl;
    }

    return 0;
}
