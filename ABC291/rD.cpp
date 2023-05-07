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
    #define debugP() std::cerr << "Line:" << __LINE__ << '\n'
#else
    #define debug(X)
    #define debugV(X)
    #define debugVL(Y)
    #define debugWL(Z)
    #define debugP()
#endif

const i64 MOD = 998244353;

using mint = atcoder::modint998244353;

int main() {
    int N;
    cin >> N;
    vector<i64> A(N, 0), B(N, 0);
    for(int i = 0; i < N; i++){
        cin >> A.at(i) >> B.at(i);
    }

    vector<vector<mint>> card(N, vector<mint>(2));
    for(int i = 0; i < N; i++){
        card.at(i).at(0) = A.at(i);
        card.at(i).at(1) = B.at(i);
    }

    vector<vector<mint>> dp(N+1, vector<mint>(2));
    // [i][p] :=  前から i 枚目までを見て、 i枚目に p を選んだ時の条件を満たす通り数
    // p = 0  表 ,  p = 1  裏

    dp.at(1).at(0) = 1;
    dp.at(1).at(1) = 1;

    for(int i = 1; i < N; i++){
        for(int p = 0; p < 2; p++){
            for(int q = 0; q < 2; q++){
                if(card.at(i).at(p) != card.at(i-1).at(q)){
                    dp.at(i+1).at(p) += dp.at(i).at(q);
                }
            }
        }
    }

    mint ans = dp.at(N).at(0) + dp.at(N).at(1);
    cout << ans.val() << endl;

    return 0;
}