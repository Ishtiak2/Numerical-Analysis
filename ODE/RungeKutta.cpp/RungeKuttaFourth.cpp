#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

double df(double x, double y) {
    return (1 + 4*x) * sqrt(y);
}

double RungeKutta(double x0, double y0, double h,double end) {
    double x,y;

    cout <<"x: " << x0 <<"       " <<"y: " <<y0 << endl;
    
    while(x < end) {
        double k1 = df(x0,y0);
        double k2 = df(x0 + h/2, y0 + (h * k1)/2);
        double k3 = df(x0 + h/2, y0 + (h * k2)/2);
        double k4 = df(x0 + h, y0 + h*k3);

        y = y0 + (h/6) * (k1 + 2*k2 + 2*k3+ k4);
        x += h;

        cout <<"x: " << x <<"       " <<"y: " <<y << endl;
        
        x0 = x;
        y0 = y;

    }

    return y;
}
int main()
{
    double x0,y0;
    x0 = 0;
    y0 = 1;
    double h = 0.25;
    double end = 1;

    cout <<fixed <<setprecision(6) << RungeKutta(x0,y0,h, end) <<endl;
    return 0;
}