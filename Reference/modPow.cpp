#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

const i64 MOD = 1000000007;


// x^n (mod m) を求める
// 一応 x < 0 の時の動作は未確認
i64 modPow(i64 x, i64 n, i64 m){
    i64 ret = 1;
    while(n > 0){
        if(n % 2 == 1){
            ret *= x;
            ret %= m;
        }
        x *= x;
        x %= m;
        n /= 2;
    }

    return ret;
}


int main() {
    cout << modPow(3, 45, MOD) << endl;
}