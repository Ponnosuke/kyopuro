/*
    
*/

#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;
using mint = atcoder::modint998244353;

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
    i64 N;
    cin >> N;
    vector<i64> a(N), b(N);
    for(int i = 0; i < N; i++)  cin >> a.at(i);
    for(int i = 0; i < N; i++)  cin >> b.at(i);

    debugP();

    vector<vector<mint>> dp(N+1, vector<mint>(3010, 0));
    dp.at(0).at(0) = 1;
    for(int i = 0; i < N; i++){
        for(int c = a.at(i); c <= b.at(i); c++){
            for(int j = 0; j <= c; j++){
                dp.at(i+1).at(c) += dp.at(i).at(j);
            }
        }

        if(i % 100 == 0){
            debugVL(i);
        }
    }

    debugP();

    mint sum = 0;
    for(int i = 0; i < 3000; i++){
        sum += dp.at(N).at(i);
    }

    debugP();

    cout << sum.val() << '\n';
}