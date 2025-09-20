#include <bits/stdc++.h>
#include<iomanip>

using namespace std;

double df(double x, double y) {
    return x * y;
}

void HeunsMethod(double x0, double y0, double h, double end) {
    double x = x0;
    double y = y0;

    cout << fixed << setprecision(6);
    cout << "X = " << x << "  Y = " << y << endl;

    while (x < end - 1e-9) {
        double y_new = y + h * ((df(x, y) + df(x + h, (y + h * df(x, y)))) / 2.0);

        x += h;
        y = y_new;

        cout << "X = " << x << "  Y = " << y << endl;
    }
}

int main() {
    HeunsMethod(1, 1, 0.1, 1.3);
    return 0;
}
