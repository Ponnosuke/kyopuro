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

const i64 INF = (1LL << 60);

int main() {
    i64 X;
    cin >> X;

    i64 ans = INF;
    for(i64 s = 1; s <= 9; s++){
        for(i64 d = -9; d <= 8; d++){
            i64 tmp = 0;
            for(i64 i = s; (0 <= i) && (i <= 9); i += d){
                tmp *= 10;
                tmp += i;
                if(tmp >= X){
                    ans = min(ans, tmp);
                    break;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}