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

int main() {
    int N, A, B;
    cin >> N >> A >> B;
    vector<int> X(N, 0);
    for(int i = 0; i < N; i++){
        cin >> X.at(i);
    }

    vector<vector<bool>> dp(N+1, vector<bool>(A, false));
    // dp[i][j] := 最初からi個目までを見て、余りがjとなるような数を選べるか
    dp.at(0).at(0) = true;
    for(int i = 0; i < N; i++){
        for(int r = 0; r < A; r++){
            if(dp.at(i).at(r)){
                dp.at(i+1).at(r) = true;

                int nr = (r + X.at(i)) % A;
                dp.at(i+1).at(nr) = true;
            }
        }
    }

    cout << (dp.at(N).at(B) ? "Yes" : "No") << '\n';
}