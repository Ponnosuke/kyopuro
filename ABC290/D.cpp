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
    int T;
    cin >> T;

    while(T--){
        i64 N, D, K;
        cin >> N >> D >> K;

        if(D % N != 0){
            D %= N;
        }
        K--;
        i64 oneLoop = ((lcm(N, D)) / D);
        i64 loopCnt = K / oneLoop;
        i64 remCnt = K % oneLoop;

        i64 ans = ((loopCnt + D * remCnt) % N);

        cout << ans << '\n';
    }
}