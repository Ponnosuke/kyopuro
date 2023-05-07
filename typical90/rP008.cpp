#include <bits/stdc++.h>
#include <atcoder/modint>
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

const string TABLE = "atcoder";

int main() {
    using mint = atcoder::modint1000000007;

    i64 N;
    cin >> N;
    string S;
    cin >> S;

    int Tsize = TABLE.size();
    vector<vector<mint>> dp(N+1, vector<mint>(Tsize + 1, mint(0)));
    dp.at(0).at(0) = 1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= Tsize; j++){
            dp.at(i+1).at(j) += dp.at(i).at(j);

            if(j < Tsize && S.at(i) == TABLE.at(j)){
                dp.at(i+1).at(j+1) += dp.at(i).at(j);
            }
        }
    }

    cout << dp.at(N).at(Tsize).val() << '\n';
}