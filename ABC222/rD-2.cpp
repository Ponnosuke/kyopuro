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

int main() {
    i64 N;
    cin >> N;
    vector<i64> a(N), b(N);
    for(int i = 0; i < N; i++)  cin >> a.at(i);
    for(int i = 0; i < N; i++)  cin >> b.at(i);

    vector<vector<i64>> dp(N+1, vector<i64>(3010, 0));
    for(int i = 0; i <= 3000; i++){
        dp.at(0).at(i) = 1;
    }
    for(int i = 0; i < N; i++){
        for(int c = a.at(i); c <= b.at(i); c++){
            dp.at(i).at(c) %= MOD;
            dp.at(i+1).at(c) += dp.at(i).at(c);
            dp.at(i+1).at(c) %= MOD;
        }

        for(int j = 0; j < 3000; j++){
            dp.at(i+1).at(j) %= MOD;
            dp.at(i+1).at(j+1) += dp.at(i+1).at(j);
            dp.at(i+1).at(j+1) %= MOD;
        }
    }

    // debug
    debugWL(dpTable);
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= 3; j++){
            debug(dp.at(i).at(j));
        }
        debugWL();
    }
    debugWL();

    cout << dp.at(N).at(b.at(N-1)) % MOD << '\n';

    return 0;
}