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
    vector<vector<int>> A(6, vector<int>(6, 0));
    for(int i = 1; i <= 4; i++){
        cin >> A.at(1).at(i);
    }

    for(int i = 1; i <= 4; i++){
        for(int j = 1; j <= 4; j++){
            A.at(i).at(j) += (A.at(i-1).at(j-1) + A.at(i-1).at(j) + A.at(i-1).at(j+1));
        }
    }

    cout << A.at(4).at(4) << '\n';
}