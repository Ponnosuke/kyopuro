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
    int N, M;
    cin >> N >> M;
    vector<int> A(N-1, 0);
    for(int i = 0; i < N-1; i++){
        cin >> A.at(i);
    }

    vector<vector<bool>> dp(N, vector<bool>(M, false));
    dp.at(0).at(0) = true;
    for(int i = 1; i < N; i++){
        for(int j = 0; j < M; j++){
            if(j - A.at(i-1) >= 0){
                if(dp.at(i-1).at(j-A.at(i-1))){
                    dp.at(i).at(j) = true;
                }
            }

            if(dp.at(i-1).at(j)){
                dp.at(i).at(j) = true;
            }
        }
    }

    int cnt = 0;
    for(int j = 0; j < M; j++){
        if(dp.at(N-1).at(j)){
            cnt++;
        }
    }

    cout << cnt << endl;
}