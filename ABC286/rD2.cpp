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
    int N, X;
    cin >> N >> X;
    vector<int> A(N, 0), B(N, 0);
    for(int i = 0; i < N; i++){
        cin >> A.at(i) >> B.at(i);
    }

    vector<vector<bool>> dp(N+1, vector<bool>(X+1, false));
    dp.at(0).at(0) = true;
    // dp[i][j] := (i : 0-indexed) A_i までの硬貨を B_i 枚まで使って j 円を払えるか
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= X; j++){
            for(int k = 0; k <= B.at(i); k++){
                if(j - k*A.at(i) >= 0){
                    if(dp.at(i).at(j - k*A.at(i))){
                        dp.at(i+1).at(j) = true;
                    }
                }
            }
        }
    }

    cout << (dp.at(N).at(X) ? "Yes" : "No") << '\n';
}