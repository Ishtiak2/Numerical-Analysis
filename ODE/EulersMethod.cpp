#include <bits/stdc++.h>
#include<iomanip>

using namespace std;

double df(double x, double y) {
    return -x * y* y;
}

void EulersMethod(double x0, double y0, double h, double end) {
    double y;
    
    while(x0 < end) {
        y = y0 + df(x0,y0) * h;
        
        cout <<"x =     " << x0 <<"     "<<"y = " << y0 << endl;
        x0 += h;
        y0 = y;
    }
}

int main() {
    cout << fixed << setprecision(6);

    EulersMethod(2, 1, 0.05, 2.2);
    return 0;
}
