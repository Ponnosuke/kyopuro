#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

const i64 INF = 1e17;

int main() {
    int N;
    cin >> N;
    
    // A[T][X]  時刻 T に位置 X にいる時に手に入る大きさ
    vector<vector<i64>> A(100010, vector<i64>(5, 0));
    int Tn = -1;
    for(int i = 0; i < N; i++){
        int t, x;
        cin >> t >> x;
        i64 tmpA;
        cin >> tmpA;

        A.at(t).at(x) = tmpA;
        if(i == N-1)  Tn = t;
    }

    // dp[t][x]  時刻 t に位置 x にいる状態で得られる大きさの合計の最大値
    vector<vector<i64>> dp(100010, vector<i64>(5, -INF));
    dp.at(0).at(0) = 0;
    for(int t = 0; t < Tn; t++){
        for(int x = 0; x < 5; x++){
            if(x > 0){
                dp.at(t+1).at(x) = max(dp.at(t+1).at(x), dp.at(t).at(x-1) + A.at(t+1).at(x));
            }

            dp.at(t+1).at(x) = max(dp.at(t+1).at(x), dp.at(t).at(x) + A.at(t+1).at(x));

            if(x < 4){
                dp.at(t+1).at(x) = max(dp.at(t+1).at(x), dp.at(t).at(x+1) + A.at(t+1).at(x));
            }
        }
    }

    i64 ans = -INF;
    for(int i = 0; i < 5; i++){
        ans = max(ans, dp.at(Tn).at(i));
    }

    cout << ans << endl;
}