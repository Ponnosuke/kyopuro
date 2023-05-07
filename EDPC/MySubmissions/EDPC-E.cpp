#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

const i64 INF = 1e15;
const i64 MAXV = 100010;

int main() {
    int N;
    cin >> N;
    i64 W;
    cin >> W;
    vector<i64> weight(N), value(N);
    for(int i = 0; i < N; i++)  cin >> weight.at(i) >> value.at(i);

    vector<vector<i64>> dp(N+1, vector<i64>(MAXV, INF));  
    // dp[i][j]  i個の中から価値の総和が j になるように選んだ時の重さの最小値
    dp.at(0).at(0) = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < MAXV; j++){
            if(j < value.at(i)){
                dp.at(i+1).at(j) = dp.at(i).at(j);
            }
            else{
                dp.at(i+1).at(j) = min(dp.at(i).at(j), dp.at(i).at(j-value.at(i)) + weight.at(i));
            }
        }
    }

    i64 ans;
    for(i64 v = 0; v < MAXV; v++){
        if(dp.at(N).at(v) <= W)  ans = v;
    }

    cout << ans << endl;

    return 0;
}