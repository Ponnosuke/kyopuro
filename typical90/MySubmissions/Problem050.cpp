#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

const i64 MOD = 1000000007LL;

int main() {
    i64 N, L;
    cin >> N >> L;

    vector<i64> dp(N+L+10, 0);
    dp.at(0) = 1;
    for(int i = 0; i < N; i++){
        dp.at(i+1) += (dp.at(i) % MOD);
        dp.at(i+1) %= MOD;
        dp.at(i+L) += (dp.at(i) % MOD);
        dp.at(i+L) %= MOD;
    }

    cout << dp.at(N) << endl;
}