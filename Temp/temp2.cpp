#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << X << " "
    #define debugV(X) std::cerr << #X << " = " << X << ", "
    #define debugVL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugWL(Z) std::cerr << #Z << '\n'
#else
    #define debug(X)
    #define debugV(X)
    #define debugVL(Y)
    #define debugWL(Z)
#endif

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
    i64 N, M, P;
    cin >> N >> M >> P;
    cout << modPow(N, P, M) << '\n';
}