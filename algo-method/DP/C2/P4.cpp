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
    
    vector<vector<i64>> field(N, vector<i64>(N, 0));
    field.at(0).at(0) = 1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(0 <= i-1){
                field.at(i).at(j) += field.at(i-1).at(j);
            }
            if(0 <= j-1){
                field.at(i).at(j) += field.at(i).at(j-1);
            }
        }
    }

    cout << field.at(N-1).at(N-1) << '\n';
}