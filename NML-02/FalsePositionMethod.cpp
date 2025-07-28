#include<bits/stdc++.h>
using namespace std;

const float es = 1e-4;

float f(float x) {
    return log(3*x) - 3;
}

float FalsePosition(float a, float b) {
    if(f(a) * f(b) > 0) return -10000;
    float err = abs(a-b);
    float c;

    long long iteration = 0;

    while(err >= es) {
        c = (a * f(b) - b * f(a))/(f(b) - f(a));
        if(f(c) == 0) {
            break;
        }
        else if(f(a) * f(c) < 0) {
            b = c;
        }

        else a = c;
        err = abs(a-b);
        iteration++;
    }

    cout <<"Iterations :" << iteration << endl;
    return c; 
}

int main()
{
    cout << FalsePosition(1,10) << endl;
    return 0;
}