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
    i64 N, M;
    cin >> N >> M;

    i64 ans = INF;
    // a <= b
    for(i64 a = 1; a <= N; a++){
        i64 b = (M + (a-1)) / a;
        if(b <= N){
            ans = min(ans, a*b);
        }

        if(a > b){
            break;
        }
    }

    if(ans == INF){
        cout << -1 << endl;
    }
    else{
        cout << ans << endl;
    }

    return 0;
}