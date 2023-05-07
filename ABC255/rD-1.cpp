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
    i64 N, Q;
    cin >> N >> Q;
    vector<i64> A(N, 0);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }
    sort(A.begin(), A.end());
    vector<i64> S(N+1, 0);
    for(int i = 0; i < N; i++){
        S.at(i+1) = S.at(i) + A.at(i);
    }
    vector<i64> X(Q, 0);
    for(int i = 0; i < Q; i++){
        cin >> X.at(i);
    }

    for(int query = 0; query < Q; query++){
        i64 nowX = X.at(query);

        i64 posX = distance(A.begin(), lower_bound(A.begin(), A.end(), nowX));
        i64 Lcnt = posX, Rcnt = N - posX;
        i64 ans = 0;
        ans += nowX*Lcnt - (S.at(posX) - S.at(0));
        ans += (S.at(N) - S.at(posX)) - nowX*Rcnt;

        cout << ans << '\n';
    }

    return 0;
}