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

const i64 INF = (1LL << 60);

int main() {
    i64 N, A, B;
    cin >> N >> A >> B;
    string S;
    cin >> S;

    i64 ans = INF;
    i64 tmp1 = 0;
    for(int rep = 0; rep < N; rep++){
        i64 tmp2 = 0;
        debugWL(pointA);
        for(int i = 0; i < (N/2); i++){
            if(S.at(i) != S.at(N - 1 - i)){
                tmp2 += B;
            }
        }
        debugWL(pointB);
        ans = min(ans, tmp1 + tmp2);
        tmp1 += A;
        string next = S.substr(1, N-1) + S.at(0);
        S = next;
    }

    cout << ans << '\n';
}