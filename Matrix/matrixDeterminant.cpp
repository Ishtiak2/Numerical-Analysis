#include <bits/stdc++.h>
#include<iomanip>

using namespace std;

double arr[25][25]; // arrrix array

void gaussElimination(int n) {
    
    for (int i = 1; i <= n; i++) {
        
        if (fabs(arr[i][i]) < 1e-9) {
            // pivot is zero so determinant will be zero
            continue;
        }
        
        for (int r = i + 1; r <= n; r++) {
            double factor = arr[r][i] / arr[i][i];
            for (int c = i; c <= n; c++) {
                arr[r][c] -= factor * arr[i][c];
            }
        }
    }
}

double findDeterminant(int n) {
    double det = 1.0;
    for (int i = 1; i <= n; i++) {
        det *= arr[i][i];
    }
    return det;
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    gaussElimination(n);

    double det = findDeterminant(n);
    cout << fixed << setprecision(6) << det << endl;

    return 0;
}