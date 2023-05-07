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

const i64 MOD = 998244353;

int main() {
    int Q;
    cin >> Q;

    deque<int> dq;
    dq.push_back(1);
    i64 times = 1;
    i64 now = 1;

    i64 modinv10 = modinv(10, MOD);

    while(Q--){
        int type;
        cin >> type;

        if(type == 1){
            i64 x;
            cin >> x;

            dq.push_back(x);
            now *= 10;
            now %= MOD;

            now += x;
            now %= MOD;

            times *= 10;
            times %= MOD;
        }
        if(type == 2){
            i64 sub = dq.front();
            dq.pop_front();
            sub *= times;
            sub %= MOD;

            now = (now - sub + MOD) % MOD;

            times *= modinv10;
            times %= MOD;
        }
        if(type == 3){
            cout << now << '\n';
        }
    }
}