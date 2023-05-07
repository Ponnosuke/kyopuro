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

const int GETA = 50000;
const int INF = (1 << 30);

int main() {
    int N;
    cin >> N;
    vector<int> W(N, 0);
    for(int i = 0; i < N; i++){
        cin >> W.at(i);
    }

    vector<vector<bool>> dp(N+1, vector<bool>(50001 + GETA, false));
    dp.at(0).at(GETA) = true;
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= 50000 + GETA; j++){
            if(!dp.at(i).at(j)){
                continue;
            }

            if(j-W.at(i) >= 0){
                dp.at(i+1).at(j-W.at(i)) = true;
            }
            if(j+W.at(i) <= 50000 + GETA){
                dp.at(i+1).at(j+W.at(i)) = true;
            }
        }
    }

    int ans = INF;
    for(int j = 0; j < 50001 + GETA; j++){
        if(dp.at(N).at(j)){
            ans = min(ans, abs(j - GETA));
        }
    }

    cout << ans << endl;
}