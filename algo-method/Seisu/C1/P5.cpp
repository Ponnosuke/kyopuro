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
    vector<bool> isPrime(N+1, true);

    for(i64 i = 2; i*i <= N; i++){
        if(!isPrime.at(i)){
            continue;
        }

        for(i64 a = i*2; a <= N; a += i){
            isPrime.at(a) = false;
        }
    }

    i64 ans = -1;
    for(i64 p = 2; p <= (N/2); p++){
        if(!isPrime.at(p)){
            continue;
        }

        i64 q = N - p;
        if(isPrime.at(q)){
            ans = p;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}