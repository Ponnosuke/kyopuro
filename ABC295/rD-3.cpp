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
    for(i64 i = 0; i < S.size(); i++){
        now ^= (1 << (int)(S.at(i) - '0'));
        cnt.at(now)++;
    }

    // debug
    // for(int i = 0; i < (1 << 10); i++){
    //     if(cnt.at(i) > 0){
    //         bitset<10> bs(i);
    //         debugV(cnt.at(i));
    //         debugVL(bs);
    //         debugWL();
    //     }
    // }

    i64 ans = 0;
    for(i64 i = 0; i < (1 << 10); i++){
        ans += cnt.at(i)*(cnt.at(i) - 1)/2;
    }

    cout << ans << endl;
}