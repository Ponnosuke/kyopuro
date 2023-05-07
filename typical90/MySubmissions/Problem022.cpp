#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    ui64 A, B, C;
    cin >> A >> B >> C;

    ui64 cubeUnit = gcd(A, gcd(B, C));
    ui64 ans = 0;
    ans += (A / cubeUnit) - 1;
    ans += (B / cubeUnit) - 1;
    ans += (C / cubeUnit) - 1;

    cout << ans << "\n";

    return 0;
}