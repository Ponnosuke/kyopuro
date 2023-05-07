#include <bits/stdc++.h>
#include <atcoder/modint>

using namespace std;
using mint = atcoder::modint998244353;

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

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<mint>> dp(N+1, vector<mint>(K+1, mint::raw(0)));
    for(int i = 0; i <= K; i++){
        dp.at(0).at(i) = mint::raw(1);
    }
    for(int i = 0; i < N; i++){
        for(int j = K; j >= 1; j--){
            dp.at(i+1).at(j) += (dp.at(i).at(j-1) - dp.at(i).at(max(0, j - M - 1)));
        }

        for(int j = 0; j < K; j++){
            dp.at(i+1).at(j+1) += dp.at(i+1).at(j);
        }
    }

    cout << dp.at(N).at(K).val() << endl;
}