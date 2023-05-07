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
    i64 N, M, K;
    cin >> N >> M >> K;

    debugP();

    vector<vector<i64>> dp(N+1, vector<i64>(K+1, 0));
    dp.at(0).at(0) = 1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < K; j++){
            for(int add = 1; add <= M; add++){
                if(j + add <= K){
                    dp.at(i).at(j) %= MOD;
                    dp.at(i+1).at(j + add) += dp.at(i).at(j);
                    dp.at(i+1).at(j + add) %= MOD;
                }
            }
        }
    }

    debugP();

    i64 ans = 0;
    for(int i = 1; i <= K; i++){
        ans += dp.at(N).at(i);
        ans %= MOD;
    }

    cout << ans << endl;
}