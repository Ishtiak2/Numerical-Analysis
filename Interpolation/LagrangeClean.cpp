#include<bits/stdc++.h>
#include<iomanip>
using namespace std;

double lagrange(int n, double p, double x[], double y[]) {
    double l[1000];
    double up,down;
    double px = 0;

    for(int i = 0; i < n; i++) {
        up = down = 1;

        for(int j = 0; j < n; j++) {
            
            if(j == i) {
                continue;
            }
            
            up = up * (p-x[j]);
            down = down * (x[i] - x[j]);
        }
        l[i] = up / down;
        
        px = px + (l[i] * y[i]);

    }

    return px;
}
int main()
{
    
    int n;
    
    cout <<"Enter the number of data: " << endl;
    cin >> n;

    double x[1000];
    double y[1000];

    cout << "Enter x values: " << endl;

    for(int i = 0; i < n; i++) {
        cin >> x[i];        
    }

    cout << "Enter y values: " << endl;

    for(int i = 0; i < n; i++) {
        cin >> y[i];        
    }

    double p;

    cout << "Enter the point to interpolate: ";
    cin >> p;

    cout <<"Interpolated value at x = " <<p <<" is "<< lagrange(n,p,x,y) << endl;

    return 0;
}