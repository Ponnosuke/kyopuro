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
    i64 G, M;
    cin >> G >> M;

    if(M % G != 0){
        cout << -1 << endl;

        return 0;
    }

    i64 num = M / G;
    i64 ans = INF;
    for(i64 i = 1; i*i <= num; i++){
        if(num % i != 0){
            continue;
        }

        i64 A = i, B = num/i;
        i64 gcdAB = gcd(A, B);
        if(gcdAB == 1){
            A *= G;
            B *= G;

            ans = min(ans, A+B);
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