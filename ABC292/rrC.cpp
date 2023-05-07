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
    i64 N;
    cin >> N;

    vector<i64> cnt(N+1, 0);
    for(i64 i = 1; i <= N; i++){
        for(i64 j = 1; i*j <= N; j++){
            cnt.at(i*j)++;
        }
    }

    i64 ans = 0;
    for(i64 i = 1; i <= N; i++){
        ans += (cnt.at(i) * cnt.at(N-i));
    }

    cout << ans << endl;
}