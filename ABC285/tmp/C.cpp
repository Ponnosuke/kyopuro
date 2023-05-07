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

const i64 ALNUM = 26;

int main() {
    string S;
    cin >> S;
    i64 size = S.size();
    i64 ans = 1;

    i64 add = 1;
    for(i64 i = 1; i < size; i++){
        add *= ALNUM;
        ans += add;
    }

    for(i64 i = 0; i < size; i++){
        i64 cnt = S.at(i) - 'A';
        ans += cnt * add;
        add /= ALNUM;
    }

    cout << ans << '\n';
}