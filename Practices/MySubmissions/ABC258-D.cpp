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

const i64 INF = (1LL << 61);

int main() {
    i64 N, X;
    cin >> N >> X;

    vector<i64> A(N), B(N);
    for(int i = 0; i < N; i++){
        cin >> A[i] >> B[i];
    }

    vector<i64> vec(N, INF);
    i64 add = 0;
    for(i64 i = 0; i < min(N, X); i++){
        add += (B[i] + A[i]);

        vec[i] = (B[i]*(X - (i+1)) + add);
    }

    i64 ans = INF;
    for(int i = 0; i < N; i++){
        ans = min(ans, vec[i]);
    }

    cout << ans << '\n';
}