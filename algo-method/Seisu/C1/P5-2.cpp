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

bool isPrime(i64 n){
    if(n < 2){
        return false;
    }

    for(i64 a = 2; a*a <= n; a++){
        if(n % a == 0){
            return false;
        }
    }

    return true;
}

int main() {
    i64 N;
    cin >> N;
    i64 ans = -1;
    for(i64 p = 2; p <= N; p++){
        if(isPrime(p)){
            i64 q = N - p;

            if(isPrime(q)){
                ans = p;
                break;
            }
        }
    }

    cout << ans << endl;
}