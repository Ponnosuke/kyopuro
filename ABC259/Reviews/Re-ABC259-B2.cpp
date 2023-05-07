#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

const double PI = acos(-1);

int main() {
    double a,b,d;
    cin >> a >> b >> d;

    double dRad = d*(PI/180);

    double ansX = a*cos(dRad) - b*sin(dRad);
    double ansY = a*sin(dRad) + b*cos(dRad);

    cout << fixed << setprecision(20);
    cout << ansX << " " << ansY << endl;
}