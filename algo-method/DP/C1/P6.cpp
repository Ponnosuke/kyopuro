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
    int N, M;
    cin >> N >> M;
    vector<int> D(M);
    for(int i = 0; i < M; i++){
        cin >> D.at(i);
    }

    vector<bool> visited(N+1, false);
    visited.at(0) = true;


    for(int i = 0; i < N+1; i++){
        for(int j = 0; j < M; j++){
            if(i + D.at(j) <= N){
                if(visited.at(i)){
                    visited.at(i + D.at(j)) = true;
                }   
            }
        }
    }

    cout << (visited.at(N) ? "Yes" : "No") << endl;
}