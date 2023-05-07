#include <bits/stdc++.h>
#include<atcoder/modint>
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

using mint = atcoder::modint1000000007;

int main() {
    int K;
    cin >> K;

    if(K % 9 != 0){
        cout << 0 << '\n';

        return 0;
    }

    vector<mint> dp(K+1, 0);
    dp[0] = 1;
    for(int i = 0; i < K; i++){
        for(int j = 1; j <= 9; j++){
            if(i+j <= K){
                dp[i+j] += dp[i];
            }
        }
    }

    cout << dp[K].val() << '\n';

    return 0;
}