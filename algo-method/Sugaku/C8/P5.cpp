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
    int N, M;
    cin >> N >> M;
    vector<i64> P(N+1, 0), D(M, 0);
    for(int i = 1; i <= N; i++){
        cin >> P.at(i);
    }
    for(int i = 0; i < M; i++){
        cin >> D.at(i);
    }

    i64 nume = 1, deno = 1;
    for(int i = 0; i < M; i++){
        nume *= P.at(D.at(i));
        deno *= 100;
    }

    cout << fixed << setprecision(15);
    cout << (double)nume / (double)deno << endl;
}