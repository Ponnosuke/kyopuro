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
    int H, W, R, C;
    cin >> H >> W >> R >> C;

    int ans = 0;
    if(R > 1){
        ans++;
    }
    if(R < H){
        ans++;
    }
    if(C > 1){
        ans++;
    }
    if(C < W){
        ans++;
    }

    cout << ans << endl;
}