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
    vector<int> A(N-1, 0), B(N-1, 0);
    for(int i = 0; i < N-1; i++)  cin >> A.at(i);
    for(int i = 0; i < N-1; i++)  cin >> B.at(i);

    vector<vector<int>> dp(N, vector<int>(M, -1));
    // dp[i][j] := i行目j列で得られるポイントの最大数
    dp.at(0).at(0) = 0;
    for(int i = 0; i < N-1; i++){
        for(int j = 0; j < M; j++){
            if(dp.at(i).at(j) == -1){
                continue;
            }

            dp.at(i+1).at(j) = max(dp.at(i+1).at(j), dp.at(i).at(j));

            if(j + A.at(i) < M){
                dp.at(i+1).at(j + A.at(i)) = max(dp.at(i+1).at(j + A.at(i)), dp.at(i).at(j) + B.at(i));
            }
        }
    }

    cout << dp.at(N-1).at(M-1) << '\n';
}