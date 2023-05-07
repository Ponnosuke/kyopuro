#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << #X << " = " << X << ", "
    #define debugL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugP(Z) std::cerr << #Z << '\n'
#else
    #define debug(X) 3389
    #define debugL(Y) 3390
    #define debugP(Z) 3391
#endif

const int MOD = 100;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N, 0));
    for(int i = 0; i < N; i++){
        cin >> A.at(0).at(i);
    }

    for(int i = 1; i < N; i++){
        for(int j = 0; j < N; j++){
            if(0 <= j-1){
                A.at(i).at(j) += A.at(i-1).at(j-1);
                A.at(i).at(j) %= MOD;
            }

            A.at(i).at(j) += A.at(i-1).at(j);
            A.at(i).at(j) %= MOD;

            if(j+1 < N){
                A.at(i).at(j) += A.at(i-1).at(j+1);
                A.at(i).at(j) %= MOD;
            }
        }
    }

    cout << A.at(N-1).at(N-1) << '\n';
}