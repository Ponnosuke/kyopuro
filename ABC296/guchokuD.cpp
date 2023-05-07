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

const i64 INF = (1LL << 60);

int main() {
    i64 N, M;
    cin >> N >> M;

    if(M % N == 0){
        if(M/N == N){
            cout << M << '\n';
            debugP();
            return 0;
        }
    }

    if((M/N) >= N){
        cout << -1 << '\n';
        debugP();
        return 0;
    }

    i64 X = INF;
    for(i64 i = 1; i <= N; i++){
        for(i64 j = 1; j <= N; j++){
            if(M <= i*j){
                X = min(X, i*j);
            }
        }
    }

    if(X == INF){
        cout << -1 << '\n';
    }
    else{
        cout << X << '\n';
    }
}