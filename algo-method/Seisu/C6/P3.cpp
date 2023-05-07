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
    i64 A, B, C, D;
    cin >> A >> B >> C >> D;

    i64 dx = abs(A - C), dy = abs(B - D);
    debugV(dx);
    debugVL(dy);
    i64 ans = -1;
    if(dx == 0){
        ans = dy - 1;
    }
    else if(dy == 0){
        ans = dx - 1;
    }
    else{
        i64 G = gcd(dx, dy);
        debugVL(G);
        i64 unitX = dx / G;

        ans = max((dx / unitX) - 1, (i64)0);
    }

    cout << ans << endl;
}