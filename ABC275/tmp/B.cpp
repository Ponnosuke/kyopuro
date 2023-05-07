#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

const i64 MOD = 998244353;

int main() {
    i64 A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;

    i64 tmp1 = (A % MOD);
    tmp1 *= (B % MOD);
    tmp1 %= MOD;
    tmp1 *= (C%MOD);
    tmp1 %= MOD;

    i64 tmp2 = (D % MOD);
    tmp2 *= (E%MOD);
    tmp2 %= MOD;
    tmp2 *= (F%MOD);
    tmp2 %= MOD;

    i64 ans = (((tmp1 - tmp2) % MOD) + MOD ) % MOD;
    cout << ans << endl;
}