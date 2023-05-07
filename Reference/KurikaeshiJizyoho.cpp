#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

// x^n を繰り返し二乗法で求める  O(log n) <- n のビット数だけループを繰り返すので
i64 myPower(i64 x, i64 n){
    i64 ret = 1;
    while(n > 0){
        if(n % 2 == 1){
            ret *= x;
        }
        x *= x;
        n /= 2;
    }

    return ret;
}

// MOD を求めるとき  x^n (mod MOD)
const i64 MOD = 1000000007;
i64 myPowerMod(i64 x, i64 n, i64 M){
    i64 ret = 1;
    while(n > 0){
        if(n % 2 == 1){
            ret *= x;
            ret %= M;
        }
        x *= x;
        x %= M;
        n /= 2;
    }

    return ret;
}

ui64 testPower(ui64 x, ui64 n){
    ui64 ret = 1;
    while(n > 0){
        if(n % 2 == 1){
            ret *= x;
        }
        x *= x;
        n /= 2;
    }

    return ret;
}

int main() {
    cout << "myPower(5^5) = " << myPower(5,5) << '\n';
    cout << "myPower(2^10) = " << myPower(2, 10) << '\n';
    cout << "myPower(3^4) = " << myPower(3, 4) << '\n';
    cout << "myPOwer(2^60) = " << myPower(2, 60) << '\n';
    // cout << "2^61 % MOD = " << myPowerMod(2LL, 61LL, MOD) << '\n';
    // cout << "ui64Pow 2^61 = " << testPower(2LL, 61LL) << '\n';
    // cout << "i64Pow 2^61 = " << myPower(2LL, 61LL) << '\n';
    // cout << '\n';
    // cout << "2^61 = " << (1LL << 61) << '\n';
    cout << "2^10 = " << (1 << 10) << '\n';
    cout << "2^60 = " << (1LL << 60) << '\n';
}