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
    i64 A, B;
    cin >> A >> B;

    vector<bool> isPrime(1000100, true);
    vector<bool> isPrimeIdx(B-A+1, true);
    isPrime.at(0) = isPrime.at(1) = false;

    for(i64 p = 2; p*p <= B; p++){
        if(!isPrime.at(p)){
            continue;
        }

        debugVL(p);

        for(i64 q = p*2; q*q <= B; q += p){
            isPrime.at(q) = false;
        }

        i64 ini = ((A + (p-1))/p) * p;
        debugV(ini);
        debugVL(p);
        if(ini == p){
            ini *= 2;
        }

        debugVL(ini);

        for(i64 q = ini; q <= B; q += p){
            isPrimeIdx.at(q-A) = false;
        }

        debugWL();
    }

    i64 ans = 0;
    for(i64 i = 0; i < B-A+1; i++){
        if(isPrimeIdx.at(i)){

            debugVL(i+A);

            ans++;
        }
    }

    cout << ans << endl;
}