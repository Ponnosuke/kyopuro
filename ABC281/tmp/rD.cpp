#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    i64 N, K, D;
    cin >> N >> K >> D;
    vector<i64> a(N);
    for(auto &x : a)  cin >> x;

    // dp[i][j][r] := 前から i 個目までを見て、j個選んだ時、余りがrであるような和の最大値
    vector<vector<vector<i64>>> dp(N+1, vector<vector<i64>>(K+1, vector<i64>(D, -1)));
    dp.at(0).at(0).at(0) = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < K+1; j++){
            for(i64 r = 0; r < D; r++){
                if(dp.at(i).at(j).at(r) == -1){
                    continue;
                }

                // 選ばない
                dp.at(i+1).at(j).at(r) = max(dp.at(i+1).at(j).at(r), dp.at(i).at(j).at(r));

                // 選ぶ
                if(j < K){
                    i64 nr = (r + a.at(i)) % D;
                    dp.at(i+1).at(j+1).at(nr) = max(dp.at(i+1).at(j+1).at(nr), dp.at(i).at(j).at(r) + a.at(i));
                }
            }
        }
    }

    cout << dp.at(N).at(K).at(0) << '\n';

    return 0;
}