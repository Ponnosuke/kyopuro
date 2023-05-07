#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int A, B;
    cin >> A >> B;

    double theta = atan2((double)B, (double)A);

    cout << fixed << setprecision(20);

    cout << cos(theta) << " " << sin(theta) << endl;
}