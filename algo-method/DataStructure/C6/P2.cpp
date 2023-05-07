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

const i64 MOD = 1000003;

i64 retRollHash(string S, i64 B){
    i64 sSize = S.size();

    i64 ret = 0;
    i64 times = 1;
    for(int i = sSize-1; i >= 0; i--){
        i64 add = (i64)(S.at(i) - 'a' + 1);
        add *= times;
        add %= MOD;
        ret += add;
        ret %= MOD;
        times *= B;
        times %= MOD;
    }

    return ret % MOD;
}

int main() {
    const i64 B = 30;
    i64 N;
    cin >> N;
    vector<string> S(N);
    for(int i = 0; i < N; i++){
        cin >> S.at(i);
    }

    vector<i64> cnt(MOD + 1);

    i64 ans = 0;
    for(int i = 0; i < N; i++){
        i64 target = retRollHash(S.at(i), B);
        cnt.at(target)++;

        ans = max(ans, cnt.at(target));
    }

    cout << ans << endl;
}