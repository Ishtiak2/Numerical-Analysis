#include<bits/stdc++.h>
#include<iomanip>

using namespace std;

const double tolerance = 1e-3;
// x^5 -3x +5.

double f(double x) {
    return x*x*x*x*x -3*x +5;
}

double df(double x) {
    return 5*x*x*x*x - 3;
}

void NewtonRaphson(double a) {
    int iteration = 0;
    double error = 2;
    double x = a;
    double prev = a;

    cout <<"Iteration       " << "Xn    "<<"        Xn+1    "<< "    Error   "<< endl << endl;

    while(error >= tolerance) {
        
        if (fabs(df(x)) < 1e-8) {
            cout << "Derivative too small, method may fail." << endl;
            return;
        }

        x = x - f(x)/df(x);
        
        error = abs(x - prev);
        
        cout <<iteration <<"            " <<prev <<"    "  << x <<"    "<< error << endl;

        prev = x;
        iteration++;
    }

    cout <<"Approximate root: " << x << endl;
    cout <<"Iteration : " <<iteration << endl;

}

int main()
{
    double a = 10;
    cout << fixed << setprecision(6);
    NewtonRaphson(a);

    return 0;
}