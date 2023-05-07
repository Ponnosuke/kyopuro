#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << X << " "
    #define debugV(X) std::cerr << #X << " = " << X << ", "
    #define debugVL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugW(Z) std::cerr << #Z << '\n'
#else
    #define debug(X)
    #define debugV(X)
    #define debugVL(Y)
    #define debugW(Z)
#endif

int main() {
    string S;
    cin >> S;

    i64 base = 1;
    i64 ans = 0;
    for(int i = S.size() - 1; i >= 0; i--){
        ans += (S.at(i) - 'A' + 1) * base;
        base *= 26;
    }

    cout << ans << endl;
}