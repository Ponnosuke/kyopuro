#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

const int INF = 1e7;

int main() {
    int W;
    cin >> W;
    int N, K;
    cin >> N >> K;
    vector<int> A(N), B(N);
    for(int i = 0; i < N; i++)  cin >> A.at(i) >> B.at(i);

    vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(K+1, vector<int>(W + 1, -INF)));
    // dp[index][i][j] 
    // index個のスクリーンショットの中から, i 枚選んで幅が j　の時の重要度の最大値
    for(int i = 0; i <= N; i++){
        dp.at(i).at(0).at(0) = 0;
    }

    for(int index = 0; index < N; index++){
        for(int i = 0; i <= K; i++){
            for(int j = 0; j <= W; j++){
                // 選ばない
                dp.at(index + 1).at(i).at(j) = max(dp.at(index + 1).at(i).at(j), dp.at(index).at(i).at(j));

                // 選ぶ
                if((j >= A.at(index)) && (i > 0)){
                    dp.at(index + 1).at(i).at(j) = max(dp.at(index + 1).at(i).at(j), dp.at(index).at(i-1).at(j - A.at(index)) + B.at(index));
                }
            }
        }
    }

    int ans = -INF;
    for(int i = 0; i <= K; i++){
        for(int j = 0; j <= W; j++){
            ans = max(ans, dp.at(N).at(i).at(j));
        }
    }

    cout << ans << endl;

    return 0;
}