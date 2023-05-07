#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

const i64 INF = 1e17;

int main() {
    int N, M;
    cin >> N >> M;

    vector<i64> X(N+1, 0);
    for(int i = 1; i <= N ; i++){
        cin >> X.at(i);
    }

    // debug
    // cout << 1 << endl;

    vector<i64> bonus(N+1, 0);
    for(int i = 0; i < M; i++){
        i64 C, Y;
        cin >> C >> Y;
        bonus.at(C) = Y;
    }

    // debug
    // cout << 2 << endl;

    vector<vector<i64>> dp(N+1, vector<i64>(N+1, -INF)); // 回、カウント
    dp.at(0).at(0) = 0;

    // i -> 回数、 j -> カウント
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            // 裏遷移
            dp.at(i+1).at(0) = max(dp.at(i+1).at(0), dp.at(i).at(j));

            // 表遷移
            dp.at(i+1).at(j+1) = dp.at(i).at(j) + X.at(i+1) + bonus.at(j+1);
        }
    }

    // debug
    // cout << 3 << endl;

    i64 ans = -INF;
    for(int j = 0; j <= N; j++){
        ans = max(ans, dp.at(N).at(j));
    }

    // debug
    // cout << 4 << endl;

    cout << ans << endl;
}