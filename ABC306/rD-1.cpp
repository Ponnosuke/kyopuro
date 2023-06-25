#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << X << " "
    #define debugV(X) std::cerr << #X << " = " << X << ", "
    #define debugVL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugWL(Z) std::cerr << #Z << '\n'
    #define debugP() std::cerr << "Line:" << __LINE__ << '\n'
#else
    #define debug(X)
    #define debugV(X)
    #define debugVL(Y)
    #define debugWL(Z)
    #define debugP()
#endif

const i64 INF = (1LL << 60);

int main() {
    i64 N;
    cin >> N;
    vector<i64> X(N), Y(N);
    for(int i = 0; i < N; i++){
        cin >> X.at(i) >> Y.at(i);
    }

    vector<vector<i64>> dp(N+1, vector<i64>(2, -INF));
    // [i][j] := 前から i 個目までの料理を楽しんで、状態が j の時の美味しさ最大値
    // j = 0 お腹を壊していない、 j = 1 お腹を壊している

    dp.at(0).at(0) = 0;
    for(int i = 0; i < N; i++){
        // 食べない
        dp.at(i+1).at(0) = max(dp.at(i+1).at(0), dp.at(i).at(0));
        dp.at(i+1).at(1) = max(dp.at(i+1).at(1), dp.at(i).at(1));

        // 食べる
        if(X.at(i) == 0){
            dp.at(i+1).at(0) = max(dp.at(i+1).at(0), dp.at(i).at(1) + Y.at(i));
            dp.at(i+1).at(0) = max(dp.at(i+1).at(0), dp.at(i).at(0) + Y.at(i));
        }
        else{
            dp.at(i+1).at(1) = max(dp.at(i+1).at(1), dp.at(i).at(0) + Y.at(i));
        }
    }

    i64 ans = 0;
    ans = max(dp.at(N).at(0), dp.at(N).at(1));

    cout << ans << '\n';
}