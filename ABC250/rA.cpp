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

    int cnt = 0;
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            if(abs(i - R) + abs(j - C) == 1){
                cnt++;
            }
        }
    }

    cout << cnt << '\n';
}