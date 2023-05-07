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

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> W(N, 0), C(N, 0);
    for(int i = 0; i < N; i++)  cin >> W.at(i);
    for(int i = 0; i < N; i++)  cin >> C.at(i);
    vector<vector<int>> weights(256);
    for(int i = 0; i < N; i++){
        int iw = W.at(i), ic = C.at(i);
        weights.at(ic).push_back(iw);
    }

    vector<vector<bool>> dp(257, vector<bool>(M+1, false));
    dp.at(0).at(0) = true;

    for(int color = 0; color < 256; color++){
        dp.at(color + 1) = dp.at(color);
        for(auto ball_w : weights.at(color)){
            for(int i = 0; i <= M; i++){
                if(dp.at(color).at(i)){
                    if(i + ball_w <= M){
                        dp.at(color+1).at(i + ball_w) = true;
                    }
                }
            }
        }
    }

    cout << (dp.at(256).at(M) ? "Yes" : "No") << '\n';
}