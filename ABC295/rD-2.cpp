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
    string S;
    cin >> S;
    i64 N = S.size();
    vector<i64> X(N+1, 0);
    for(int i = 0; i < N; i++){
        char ch = S.at(i);
        X.at(i+1) = (X.at(i) ^ (1 << (int)(ch - '0')));
    }

    i64 ans = 0;
    vector<i64> cnt((1 << 10), 0);
    for(int i = 0; i <= N; i++){
        cnt.at(X.at(i))++;
    }
    for(int i = 0; i < (1 << 10); i++){
        i64 ele = cnt.at(i);
        ans += ele*(ele-1)/2;
    }

    cout << ans << endl;
}