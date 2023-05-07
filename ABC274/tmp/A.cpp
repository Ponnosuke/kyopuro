#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    double A, B;
    cin >> A >> B;
    cout << fixed << setprecision(4);

    double tmp = B / A;
    tmp = round(tmp * 1000) / 1000;
    string S = to_string(tmp).substr(0, 5);
    cout << S << endl;
    
}