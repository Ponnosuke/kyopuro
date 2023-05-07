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
    vector<i64> a(N+1, 0);
    i64 cntSame = 0;
    for(int i = 1; i <= N; i++){
        cin >> a.at(i);
        if(a.at(i) == i){
            debugV(i);
            debugVL(a.at(i));
            cntSame++;
        }
    }

    debugVL(cntSame);

    i64 cntDiff = 0;
    for(int i = 1; i <= N; i++){
        if(a.at(i) == i){
            continue;
        }
        if(a.at(a.at(i)) == i){
            debugV(i);
            debugV(a.at(i));
            debugVL(a.at(a.at(i)));
            cntDiff++;
        }
    }
    cntDiff /= 2;

    i64 ans = cntSame*(cntSame - 1)/2;
    ans += cntDiff;
    debugV(ans);
    debugVL(cntDiff);

    cout << ans << '\n';
}