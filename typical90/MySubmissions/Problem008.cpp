/*
    競プロ典型 90 問 008 - AtCounter（★4） - けんちょんの競プロ精進記録 
    https://drken1215.hatenablog.com/entry/2022/04/01/121700 
*/
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

const i64 MOD = 1000000000LL + 7LL;

const string TABLE = "atcoder";

int main() {
    i64 N;
    cin >> N;
    string S;
    cin >> S;

    int Tsize = TABLE.size();
    vector<vector<i64>> dp(N+1, vector<i64>(Tsize + 1, 0));
    dp.at(0).at(0) = 1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= Tsize; j++){
            dp.at(i+1).at(j) += dp.at(i).at(j);
            dp.at(i+1).at(j) %= MOD;

            if(j < Tsize && S.at(i) == TABLE.at(j)){
                dp.at(i+1).at(j+1) += dp.at(i).at(j);
                dp.at(i+1).at(j+1) %= MOD;
            }
        }
    }

    cout << dp.at(N).at(Tsize) << '\n';
}