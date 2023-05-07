#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

const i64 INF = 1e17;

int main() {
    int N, M;
    cin >> N >> M;
    vector<i64> A(N, 0);
    for(auto &x : A)  cin >> x;

    vector<vector<i64>> dp(N + 1, vector<i64>(M + 1, -INF));  
    // dp[i][j]  A_(i-1) までの列から (i個のA列から) j個とった時の最大値
    for(int i = 0; i <= N; i++){
        dp.at(i).at(0) = 0;
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(i >= j){
                dp.at(i+1).at(j+1) = max(dp.at(i).at(j+1), dp.at(i).at(j) + (j + 1) * A.at(i));
            }
        }
    }

    cout << dp.at(N).at(M) << endl;
}