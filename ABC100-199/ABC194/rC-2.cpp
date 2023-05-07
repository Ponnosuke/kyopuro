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
    int N;
    cin >> N;
    vector<i64> A(N, 0);
    vector<i64> S(N+1, 0);
    for(int i = 0; i < N; i++){
        i64 iA;
        cin >> iA;
        A.at(i) = iA;
        S.at(i+1) = S.at(i) + iA;
    }

    i64 ans = 0;
    for(int i = 0; i < N; i++){
        i64 nowA = A.at(i);
        ans += (N-1) * (nowA * nowA);
        ans += (-2 * nowA) * (S.at(N) - S.at(i+1));
    }

    cout << ans << '\n';
}