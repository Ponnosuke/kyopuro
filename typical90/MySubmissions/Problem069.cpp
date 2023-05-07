#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

const i64 MOD = 1000000007;

i64 myPower(i64 x, i64 n){
    i64 ret = 1;
    while(n > 0){
        if(n % 2 == 1){
            ret *= x;
            ret %= MOD;
        }
        x *= x;
        x %= MOD;
        n /= 2;
    }

    return ret;
}

int main() {
    i64 N, K;
    cin >> N >> K;

    i64 ans = 0;
    if(N == 1){
        cout << K % MOD << '\n';
    }
    else if(N == 2){
        ans = (K * (K-1)) % MOD;
        cout << ans << '\n';
    }
    else{
        ans = (((K * (K-1)) % MOD) * myPower(K-2, N-2)) % MOD;
        cout << ans << '\n';
    }

    return 0;
}