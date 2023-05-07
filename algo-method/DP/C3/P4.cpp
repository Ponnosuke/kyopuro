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
    vector<int> W(N, 0), V(N, 0);
    for(int i = 0; i < N; i++)  cin >> W.at(i);
    for(int i = 0; i < N; i++)  cin >> V.at(i);

    vector<vector<int>> dp(N+1, vector<int>(M+1, -INF));
    // dp[i][j] := 小さい方から i 個目までを使って、重さが j の時の価値の最大値
    dp.at(0).at(0) = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= M; j++){
            if(dp.at(i).at(j) < 0){
                continue;
            }

            dp.at(i+1).at(j) = max(dp.at(i+1).at(j), dp.at(i).at(j));

            if(j + W.at(i) <= M){
                dp.at(i+1).at(j+W.at(i)) = max(dp.at(i+1).at(j+W.at(i)), dp.at(i).at(j) + V.at(i));
            }
        }
    }

    int ans = -INF;
    for(int j = 0; j <= M; j++){
        ans = max(ans, dp.at(N).at(j));
    }

    cout << ans << endl;
}