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
    i64 N, K, D;
    cin >> N >> K >> D;

    vector<i64> a(N);
    for(i64 i = 0; i < N; i++){
        cin >> a.at(i);
    }

    vector<vector<vector<i64>>> dp(N+1, vector<vector<i64>>(K+1, vector<i64>(D, -1)));
    for(i64 i = 0; i <= N; i++){
        dp.at(i).at(0).at(0) = 0;
    }
    for(i64 i = 0; i < N; i++){
        for(i64 j = 0; j <= K; j++){
            for(i64 r = 0; r < D; r++){
                if(dp.at(i).at(j).at(r) != -1){
                    // 選ばない
                    dp.at(i+1).at(j).at(r) = max(dp.at(i+1).at(j).at(r), dp.at(i).at(j).at(r));

                    // 選ぶ
                    if(j+1 <= K){
                    i64 nr = (r + a.at(i)) % D;
                    dp.at(i+1).at(j+1).at(nr) = max(dp.at(i+1).at(j+1).at(nr), dp.at(i).at(j).at(r) + a.at(i));
                    }
                }
            }
        }
    }

    i64 ans = dp.at(N).at(K).at(0);
    cout << ans << endl;
}