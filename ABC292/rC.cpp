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

    i64 ans = 0;
    for(i64 x = 1; x < N; x++){
        i64 y = N - x;
        i64 cntAB = 0, cntCD = 0;

        for(i64 a = 1; a*a <= x; a++){
            if(x % a != 0){
                continue;
            }

            cntAB++;
            if(a != (x/a)){
                cntAB++;
            }
        }

        for(i64 c = 1; c*c <= y; c++){
            if(y % c != 0){
                continue;
            }

            cntCD++;
            if(c != (y/c)){
                cntCD++;
            }
        }

        ans += (cntAB * cntCD);
    }

    cout << ans << '\n';
}