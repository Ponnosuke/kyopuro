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

const i64 MOD = 1000000000LL + 7LL;

int main() {
    i64 N;
    cin >> N;
    vector<i64> C(N);
    for(int i = 0; i < N; i++){
        cin >> C.at(i);
    }

    sort(C.begin(), C.end());
    
    i64 ans = 1;
    for(int i = 0; i < N; i++){
        ans *= ((C.at(i) - i) % MOD);
        ans %= MOD;
    }

    cout << ans << '\n';
}