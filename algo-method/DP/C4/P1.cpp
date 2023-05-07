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
    int N, A;
    cin >> N >> A;
    vector<int> P(N, 0), Q(N, 0), R(N, 0);
    for(int i = 0; i < N; i++)  cin >> P.at(i);
    for(int i = 0; i < N; i++)  cin >> Q.at(i);
    for(int i = 0; i < N; i++)  cin >> R.at(i);

    vector<vector<int>> cost(N, vector<int>(3, 0));
    for(int i = 0; i < N; i++){
        cost.at(i).at(0) = P.at(i);
        cost.at(i).at(1) = Q.at(i);
        cost.at(i).at(2) = R.at(i);
    }

    vector<vector<int>> dp(N, vector<int>(3, INF));
    dp.at(0).at(0) = P.at(0);
    dp.at(0).at(1) = Q.at(0);
    dp.at(0).at(2) = R.at(0);
    for(int i = 0; i < N-1; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                if(j == k){
                    dp.at(i + 1).at(k) = min(dp.at(i + 1).at(k), dp.at(i).at(j) + cost.at(i+1).at(k) - A);
                }
                else{
                    dp.at(i + 1).at(k) = min(dp.at(i + 1).at(k), dp.at(i).at(j) + cost.at(i+1).at(k));
                }
            }
        }
    }

    int ans = INF;
    for(int i = 0; i < 3; i++){
        ans = min(ans, dp.at(N-1).at(i));
    }

    cout << ans << endl;
}