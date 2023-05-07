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

const int INF = (1 << 30);

int main() {
    int N;
    cin >> N;
    vector<vector<int>> A(2, vector<int>(N, 0));
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < N; j++){
            cin >> A.at(i).at(j);
        }
    }

    vector<vector<int>> dp(N+1, vector<int>(4, INF));
    // 1:ue, 2:sita, 3:ryouho
    dp.at(0).at(3) = 0;

    for(int i = 0; i < N; i++){
        dp.at(i+1).at(1) = min(dp.at(i).at(2), dp.at(i).at(3)) + A.at(0).at(i);
        dp.at(i+1).at(2) = min(dp.at(i).at(1), dp.at(i).at(3)) + A.at(1).at(i);
        dp.at(i+1).at(3) = min(dp.at(i).at(1), min(dp.at(i).at(2), dp.at(i).at(3))) + A.at(0).at(i) + A.at(1).at(i);
    }

    int ans = INF;
    for(int i = 0; i < 4; i++){
        ans = min(ans, dp.at(N).at(i));
    }

    cout << ans << endl;
}