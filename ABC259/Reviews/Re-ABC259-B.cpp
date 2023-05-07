#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

const double PI = acos(-1);

int main() {
    double a,b,d;
    cin >> a >> b >> d;

    double r = sqrt(a*a + b*b);
    double theta = atan2(b, a);  // rad

    double dRad = d * (PI/180);
    theta += dRad;

    double ansX = r*cos(theta), ansY = r*sin(theta);

    cout << fixed << setprecision(20);
    cout << ansX << " " << ansY << endl;
}