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

const int INF = (1 << 30);

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N, 0);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }

    vector<vector<int>> dp(N, vector<int>(K+1, -INF));
    dp.at(0).at(0) = A.at(0);
    dp.at(0).at(1) = 0;
    for(int i = 1; i < N; i++){
        // A_i を消さない
        dp.at(i).at(0) = max(dp.at(i-1).at(0), dp.at(i-1).at(K)) + A.at(i);

        // A_i を消す
        for(int j = 1; j <= K; j++){
            dp.at(i).at(j) = dp.at(i-1).at(j-1);

            if(j == K){
                dp.at(i).at(j) = max(dp.at(i-1).at(j-1), dp.at(i-1).at(j));
            }
        }
    }

    cout << max(dp.at(N-1).at(0), dp.at(N-1).at(K)) << endl;

    return 0;
}