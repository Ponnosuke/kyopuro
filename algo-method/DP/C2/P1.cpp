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

int main() {
    vector<vector<int>> A(4, vector<int>(4, 0));
    for(int j = 0; j < 4; j++){
        cin >> A.at(0).at(j);
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(0 <= i-1 && 0 <= j-1){
                A.at(i).at(j) += A.at(i-1).at(j-1);
            }
            if(0 <= i-1){
                A.at(i).at(j) += A.at(i-1).at(j);
            }
            if(0 <= i-1 && j+1 < 4){
                A.at(i).at(j) += A.at(i-1).at(j+1);
            }
        }
    }

    cout << A.at(3).at(3) << '\n';
}