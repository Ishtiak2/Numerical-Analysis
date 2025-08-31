#include<bits/stdc++.h>
#include<iomanip>
using namespace std;

double lagrange(int n, double p, double x[], double y[]) {
    double l[1000];
    double up,down;
    double px = 0;

    for(int i = 0; i < n; i++) {
        up = down = 1;

        cout << "\nL[" << i << "] = ";

        for(int j = 0; j < n; j++) {
            
            if(j == i) {
                continue;
            }

            cout << "(" << p << " - " << x[j] << ") / (" << x[i] << " - " << x[j] << ")";
            
            up = up * (p-x[j]);
            down = down * (x[i] - x[j]);

            if(j != n-1 && !(i == n-1 && j == n-2)) {
                // Add multiplication sign between terms, careful to skip the i index
                cout << " * ";
            }
            
        }
        l[i] = up / down;
        
        cout << " = " << l[i];

        px = px + (l[i] * y[i]);
        cout << ", Contribution = " << l[i] * y[i] << endl;
    }
    
    cout <<"\nInterpolated value at x = " <<p <<" is "<< px <<endl;

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

    double ans = lagrange(n,p,x,y);

    return 0;
}