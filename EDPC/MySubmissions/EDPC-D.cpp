#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N;
    cin >> N;
    i64 W;
    cin >> W;
    vector<i64> weight(N), value(N);
    for(int i = 0; i < N; i++)  cin >> weight.at(i) >> value.at(i);

    vector<vector<i64>> dp(N+1, vector<i64>(W+1, 0));  
    // dp[i][j]  i-1番目 (0-indexed) までの品物から (番号が小さい方からi個取った品物から、
    // したがってi個の品物から) 重さが j 以下になるように選んだ時の価値の最大値

    for(int i = 0; i < N; i++){
        for(int j = 0; j <= W; j++){
            if(j < weight.at(i)){
                dp.at(i+1).at(j) = dp.at(i).at(j);
            }
            else{
                dp.at(i+1).at(j) = max(dp.at(i).at(j), dp.at(i).at(j - weight.at(i)) + value.at(i));
            }
        }
    }

    cout << dp.at(N).at(W) << endl;

    return 0;
}