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
    int N;
    cin >> N;
    vector<int> W(N, 0);
    int M = 0;
    for(int i = 0; i < N; i++){
        cin >> W.at(i);
        M += W.at(i);
    }

    vector<vector<bool>> dp(N+1, vector<bool>(M+1, false));
    dp.at(0).at(0) = true;
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= M; j++){
            if(!dp.at(i).at(j)){
                continue;
            }

            dp.at(i+1).at(j+W.at(i)) = true;
            dp.at(i+1).at(abs(j-W.at(i))) = true;
        }
    }

    for(int j = 0; j <= M; j++){
        if(dp.at(N).at(j)){
            cout << j << '\n';
            break;
        }
    }

    return 0;
}