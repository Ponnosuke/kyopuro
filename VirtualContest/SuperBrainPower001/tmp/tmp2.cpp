#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    double A, B;
    cin >> A >> B;

    cout << fixed << setprecision(20);

    double dist = sqrt(A*A + B*B);
    double myCos = A / dist, mySin = B / dist;

    cout << myCos << " " << mySin << endl;
}