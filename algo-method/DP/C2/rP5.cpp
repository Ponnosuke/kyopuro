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
    vector<string> field(N);
    for(auto &S : field){
        cin >> S;
    }

    vector<vector<int>> dp(N, vector<int>(N, 0));
    dp.at(0).at(0) = 1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(field.at(i).at(j) == '#'){
                continue;
            }

            if(i-1 >= 0){
                dp.at(i).at(j) += dp.at(i-1).at(j);
            }
            if(j-1 >= 0){
                dp.at(i).at(j) += dp.at(i).at(j-1);
            }
        }
    }

    cout << dp.at(N-1).at(N-1) << '\n';
}