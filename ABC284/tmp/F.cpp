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
    i64 N;
    cin >> N;
    string T;
    cin >> T;

    for(i64 i = 0; i < N+1; i++){
        string S = T.substr(i, N);
        string tmp = "";
        if(i > 0){
            tmp += T.substr(0, i);
        }
        if(i < N){
            tmp += T.substr(i+N, )
        }
    }
}