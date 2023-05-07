/*
    計算ごり押し
    AC
*/

#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

double time(i64 A, i64 B, i64 g){
    double tmpA, tmpB, tmpG;
    tmpA = A;
    tmpB = B;
    tmpG = g;

    return (tmpA / sqrt(tmpG)) + tmpB * (tmpG - 1.0);
}

int main() {
    i64 A, B;
    cin >> A >> B;

    i64 g = A / (2LL * B);
    g = cbrt((double)g) * cbrt((double)g);
    double ans = min(time(A, B, g), time(A, B, (g+1)));

    cout << fixed << setprecision(18);
    cout << ans << '\n';
}