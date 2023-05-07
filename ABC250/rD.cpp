/*
    解説 - AtCoder Beginner Contest 250 
    https://atcoder.jp/contests/abc250/editorial/3950 
*/

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

const i64 POW6 = 1000000;

int main() {
    i64 N;
    cin >> N;

    vector<bool> isPrime(POW6 + 1, true);
    vector<i64> primes;
    isPrime.at(0) = isPrime.at(1) = false;
    for(i64 i = 2; i*i <= POW6; i++){
        if(!isPrime.at(i)){
            continue;
        }

        for(i64 j = i*i; j <= POW6; j += i){
            isPrime.at(j) = false;
        }
    }

    for(i64 i = 2; i <= POW6; i++){
        if(isPrime.at(i)){
            primes.push_back(i);
        }
    }

    vector<i64> S(POW6 + 1, 0);
    for(i64 p : primes){
        S.at(p) = 1;
    }
    for(i64 i = 0; i < POW6; i++){
        S.at(i+1) += S.at(i);
    }

    i64 ans = 0;
    for(i64 q : primes){
        i64 r = min(N/q/q/q, q-1);
        ans += S.at(r);
    }

    cout << ans << endl;
}