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

const i64 MOD = 998244353;

// x^n (mod m) を求める
// O(log n)
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

    int Q;
    cin >> Q;

    deque<i64> dq;
    dq.push_back(1);

    i64 now = 1;
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
        }
        if(type == 2){
            i64 sub = dq.front();
            dq.pop_front();
            i64 times = modPow(10LL, dq.size(), MOD);
            sub *= times;
            sub %= MOD;

            now = (now - sub + MOD) % MOD; 
        }
        if(type == 3){
            cout << now << '\n';
        }
    }

    return 0;
}