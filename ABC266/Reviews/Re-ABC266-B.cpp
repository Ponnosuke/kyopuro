#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

const i64 MOD1 = 998244353;

int main() {
    i64 N;
    cin >> N;
    cout << (N%MOD1 + MOD1) % MOD1 << endl;
}