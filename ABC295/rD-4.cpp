/*
    ABC295 D-Three Days Ago

    そこまでに今の状態と同じ状態がいくつあるか考えて、それらと作れる部分列の数を
    逐一数えていく方法
*/

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

    vector<i64> cnt((1 << 10), 0);
    i64 now = 0;
    cnt.at(now)++;
    i64 ans = 0;
    for(i64 i = 0; i < S.size(); i++){
        now ^= (1 << (int)(S.at(i) - '0'));
        ans += cnt.at(now);
        cnt.at(now)++;
    }

    cout << ans << endl;
}