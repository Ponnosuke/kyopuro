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

const int INF = (1 << 30);

int main() {
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N, 0));
    for(auto &x : A){
        for(auto &y : x){
            cin >> y;
        }
    }

    vector<vector<int>> dp(N, vector<int>(N, -INF));
    dp.at(0).at(0) = A.at(0).at(0);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i+1 < N){
                dp.at(i+1).at(j) = max(dp.at(i+1).at(j), dp.at(i).at(j) + A.at(i+1).at(j));
            }
            if(j+1 < N){
                dp.at(i).at(j+1) = max(dp.at(i).at(j+1), dp.at(i).at(j) + A.at(i).at(j+1));
            }
        }
    }

    cout << dp.at(N-1).at(N-1) << '\n';
}