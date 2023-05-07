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
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                for(int l = 1; l <= 3; l++){
                    if(j == k){
                        if(l == 1){
                            dp.at(i+1).at(j).at(l+1) = min(dp.at(i+1).at(j).at(l+1), dp.at(i).at(k).at(l) + cost.at(i+1).at(j) - A );
                        }
                        else if(l == 2){
                            dp.at(i+1).at(j).at(l+1) = min(dp.at(i+1).at(j).at(l+1), dp.at(i).at(k).at(l) + cost.at(i+1).at(j) - B ); 
                        }
                        else{
                            dp.at(i+1).at(j).at(l) = min(dp.at(i+1).at(j).at(l), dp.at(i).at(k).at(l) + cost.at(i+1).at(j) - B);
                        }
                    }
                    else{
                        dp.at(i+1).at(j).at(1) = min(dp.at(i+1).at(j).at(1), dp.at(i).at(k).at(l) + cost.at(i+1).at(j));   
                    }
                }
            }
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