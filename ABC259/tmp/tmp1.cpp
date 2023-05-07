#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

const double PI = acos(-1);

int main() {
    int a, b, d;
    cin >> a >> b >> d;

    cout << fixed << setprecision(20);

    if(a == 0 && b == 0){
        double aDouble = a, bDouble = b;
        cout << aDouble << " " << bDouble << endl;
        return 0;
    }

    double dr = d * (PI / 180.0);

    double r = sqrt(a*a + b*b);
    double xRad = acos(a/r) - dr, yRad = asin(b/r) - dr;

    double ad = r * cos(xRad), bd = r * sin(yRad);

    // debug
    /*
    cout << "r = " << r << endl;
    cout << "a/r = " << a/r << endl;
    cout << "acos(a/r) = " << acos(a/r) << endl;
    cout << "xRad = " << xRad << endl; 
    */
   
    cout << ad << " " << bd << endl;

    return 0;
}