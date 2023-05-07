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

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> W(N, 0);
    for(int i = 0; i < N; i++){
        cin >> W.at(i);
    }

    vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(M+1, vector<int>(2, 0)));
    // dp[i][j][k] := 前から i 個目まで見て、重さを j にできる、奇数個 (k=1) か偶数個 (k=0) の入れ方の数
    dp.at(0).at(0).at(0) = 1;
    for(int i = 0; i < N; i++){
        
    }
}