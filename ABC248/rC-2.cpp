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
    dp.at(0).at(0) = mint::raw(1);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < K; j++){
            for(int add = 1; add <= M; add++){
                if(j + add <= K){
                    dp.at(i+1).at(j + add) += dp.at(i).at(j);
                }
            }
        }
    }

    mint ans = mint::raw(0);
    for(int i = 0; i <= K; i++){
        ans += dp.at(N).at(i);
    }

    cout << ans.val() << endl;
}