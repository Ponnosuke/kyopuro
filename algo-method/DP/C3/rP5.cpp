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

const int INF = (1 << 30);

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> W(N, 0);
    for(int i = 0; i < N; i++){
        cin >> W.at(i);
    }

    vector<vector<int>> dp(N+1, vector<int>(M+1, INF));
    // dp[i][j] := 最初から i 個目までを見たとき、重さ j を実現できるボールの最小個数
    dp.at(0).at(0) = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= M; j++){
            if(dp.at(i).at(j) == INF){
                continue;
            }

            dp.at(i+1).at(j) = min(dp.at(i+1).at(j), dp.at(i).at(j));

            if(j + W.at(i) <= M){
                dp.at(i+1).at(j+W.at(i)) = min(dp.at(i+1).at(j+W.at(i)), dp.at(i).at(j) + 1);
            }
        }
    }

    debugWL(dp);
    for(int i = 0; i < N+1; i++){
        for(int j = 0; j < M+1; j++){
            debug(dp.at(i).at(j));
        }
        debugWL();
    }
    debugWL();

    if(dp.at(N).at(M) == INF){
        cout << -1 << '\n';
    }
    else{
        cout << dp.at(N).at(M) << '\n';
    }
}