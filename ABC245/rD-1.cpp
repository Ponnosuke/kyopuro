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

int main() {
    i64 N, M;
    cin >> N >> M;
    vector<i64> A(N+1), B(M+1, 0), C(N+M+1);

    i64 ini = 0;
    bool stop = false;
    for(int i = 0; i <= N; i++){
        cin >> A.at(i);
        if(A.at(i) != 0 && !stop){
            stop = true;
            ini = i;
        }
    }
    for(int i = 0; i <= N+M; i++){
        cin >> C.at(i);
    }

    debugP();
    for(int i = ini; i <= M + ini; i++){
        i64 sub = 0;

        for(int j = i; j > ini; j--){
            if(j > N || (i-j) > M){
                continue;
            }
            sub += A.at(j) * B.at(i-j);
        }

        B.at(i - ini) = (C.at(i) - sub) / A.at(ini);
    }

    debugP();

    for(int i = 0; i <= M; i++){
        cout << B.at(i);

        if(i < M){
            cout << " ";
        }
    }
    cout << '\n';
}