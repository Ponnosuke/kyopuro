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

const int MAX_A = 200000;
const int VEC_SIZE = MAX_A + 1;

int main() {
    int N;
    cin >> N;
    vector<i64> cnt(VEC_SIZE, 0);
    for(int i = 0; i < N; i++){
        int A;
        cin >> A;
        cnt.at(A)++;
    }

    vector<vector<i64>> dp(VEC_SIZE, vector<i64>(4, 0));
    dp.at(0).at(0) = 1;
    for(int i = 0; i < MAX_A; i++){
        for(int j = 0; j < 4; j++){
            dp.at(i+1).at(j) = dp.at(i).at(j);
        }

        for(int j = 0; j < 3; j++){
            dp.at(i+1).at(j+1) += dp.at(i).at(j) * cnt.at(i+1);
        }
    }

    cout << dp.at(MAX_A).at(3) << endl;
}