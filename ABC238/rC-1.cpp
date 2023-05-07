#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << X << " "
    #define debugV(X) std::cerr << #X << " = " << X << ", "
    #define debugVL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugWL(Z) std::cerr << #Z << '\n'
    #define debugP() std::cerr << "Line:" << __LINE__ << '\n'
#else
    #define debug(X)
    #define debugV(X)
    #define debugVL(Y)
    #define debugWL(Z)
    #define debugP()
#endif

// 非再帰のユークリッド互除法による逆元計算
// a の mod m における逆元を求める  
// a と m が互いに素でないといけないことに注意
i64 modinv(i64 a, i64 m){
    i64 b = m, s = 1, t = 0;
    while(b){
        i64 q = a / b;
        a -= q * b;
        swap(a, b);
        s -= q * t;
        swap(s, t);
    }
    s = ((s % m) + m) % m;
    return s;
}

const ui64 MOD = 998244353;

i64 modSum(i64 left, i64 right, i64 modinv2, i64 m){

    assert(right >= left);

    i64 cnt = right - left + 1;
    cnt %= m;

    i64 ret = right + left;
    ret %= m;
    ret *= cnt;
    ret %= m;
    ret *= modinv2;
    ret %= m;

    return ret;
}

int main() {
    i64 N;
    cin >> N;
    i64 keta = to_string(N).size();

    i64 ans = 0;

    i64 num = 9;
    i64 cnt = 9;
    i64 preNum = 0;

    i64 modinv2 = modinv(2, MOD);

    i64 left = 1, right = 9;
    for(int i = 1; i < keta; i++){
        ans += modSum(left, right,modinv2, MOD);
        ans %= MOD;

        right *= 10;
    }

    i64 tmp = right /= 9;
    right = (N - tmp) + 1;
    ans += modSum(left, right, modinv2, MOD);
    ans %= MOD;

    cout << ans << '\n';
}