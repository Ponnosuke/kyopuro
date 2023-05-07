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

const i64 MOD = 998244353;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<i64>> dp(N+1, vector<i64>(K+1, 0));
    // dp[i][j] := 前から i 個目までを見て、合計を j とすることができる通り数の余り
    dp.at(0).at(0) = 1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= K; j++){
            for(int a = 1; a <= M; a++){
                if(j + a <= K){
                    dp.at(i+1).at(j+a) += dp.at(i).at(j);
                    dp.at(i+1).at(j+a) %= MOD;
                }
            }
        }
    }

    i64 ans = 0;
    for(int i = 0; i <= K; i++){
        ans += dp.at(N).at(i);
        ans %= MOD;
    }

    cout << ans << '\n';
}