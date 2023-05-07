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

const int INF = 1 << 30;

int main() {
    int N, A, B;
    cin >> N >> A >> B;
    vector<int> P(N, 0), Q(N,0), R(N,0);
    for(int i = 0; i < N; i++)  cin >> P.at(i);
    for(int i = 0; i < N; i++)  cin >> Q.at(i);
    for(int i = 0; i < N; i++)  cin >> R.at(i);
    vector<vector<int>> cost(N, vector<int>(3, 0));
    for(int i = 0; i < N; i++){
        cost.at(i).at(0) = P.at(i);
        cost.at(i).at(1) = Q.at(i);
        cost.at(i).at(2) = R.at(i);
    }

    vector<vector<vector<int>>> dp(N, vector<vector<int>>(3, vector<int>(4, INF)));
    for(int i = 0; i < 3; i++){
        dp.at(0).at(i).at(1) = cost.at(0).at(i);
    }

    for(int i = 0; i < N-1; i++){
        for(int s = 0; s < 3; s++){
            for(int ps = 0; ps < 3; ps++){
                // dp.at(i+1).at(s).at(1)
                if(s != ps){
                    for(int c = 1; c <= 3; c++){
                        dp.at(i+1).at(s).at(1) = min(dp.at(i+1).at(s).at(1), dp.at(i).at(ps).at(c) + cost.at(i+1).at(s));
                    }
                }
            }

            dp.at(i+1).at(s).at(2) = min(dp.at(i+1).at(s).at(2), dp.at(i).at(s).at(1) + cost.at(i+1).at(s) - A);
            dp.at(i+1).at(s).at(3) = min(dp.at(i+1).at(s).at(3), min(dp.at(i).at(s).at(2), dp.at(i).at(s).at(3)) + cost.at(i+1).at(s) - B);
        }
    }

    int ans = INF;
    for(int j = 0; j < 3; j++){
        for(int l = 1; l <= 3; l++){
            ans = min(ans, dp.at(N-1).at(j).at(l));
        }
    }

    cout << ans << '\n';
}