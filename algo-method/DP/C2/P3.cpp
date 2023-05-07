#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << #X << " = " << X << ", "
    #define debugL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugP(Z) std::cerr << #Z << '\n'
#else
    #define debug(X) 3389
    #define debugL(Y) 3390
    #define debugP(Z) 3391
#endif

const int INF = (1 << 30);

int main() {
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(3));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 3; j++){
            cin >> A.at(i).at(j);
        }
    }

    vector<vector<int>> dp(N, vector<int>(3, -INF));  //  dp[i][j] := i 日目に 仕事j を選んだ時の最大値
    dp.at(0).at(0) = A.at(0).at(0);
    dp.at(0).at(1) = A.at(0).at(1);
    dp.at(0).at(2) = A.at(0).at(2);
    for(int i = 0; i < N-1; i++){

        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                if(j == k){
                    continue;
                }

                dp.at(i+1).at(k) = max(dp.at(i+1).at(k), dp.at(i).at(j) + A.at(i+1).at(k));
            }
        }
        
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < 3; j++){
            debug(i);
            debug(j);
            debugL(dp.at(i).at(j));
        }
    }

    int ans = -INF;
    for(int i = 0; i < 3; i++){
        ans = max(ans, dp.at(N-1).at(i));
    }

    cout << ans << '\n';
}