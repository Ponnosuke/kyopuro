#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << X << " "
    #define debugV(X) std::cerr << #X << " = " << X << ", "
    #define debugVL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugWL(Z) std::cerr << #Z << '\n'
#else
    #define debug(X)
    #define debugV(X)
    #define debugVL(Y)
    #define debugWL(Z)
#endif

i64 mySqrt(i64 n, i64 jokai){
    i64 NG = -1, OK = jokai;
    while(abs(OK - NG) > 1){
        i64 mid = OK + (NG - OK)/2;
        if(n <= mid*mid*mid*mid){
            OK = mid;
        }
        else{
            NG = mid;
        }
    }

    return OK;
}

int main() {
    ui64 N;
    cin >> N;

    ui64 cbrtN = cbrt(N) + 1;

    vector<ui64> primes;
    vector<bool> isPrime(cbrtN + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for(ui64 a = 2; a * a <= cbrtN; a++){
        if(!isPrime[a]){
            continue;
        }

        for(ui64 i = a + a; i <= cbrtN; i += a){
            isPrime[i] = false;
        }
    }

    for(ui64 i = 0; i < cbrtN + 1; i++){
        if(isPrime[i]){
            primes.push_back(i);
        }
    }

    ui64 ans = 0;
    ui64 vecSize = (ui64)primes.size();
    for(ui64 i = 0; i < vecSize; i++){
        for(ui64 j = i + 1; j< vecSize; j++){
            ui64 p = primes[i], q = primes[j];
            if(p*q*q*q <= N){
                ans++;
            }
            else{
                break;
            }
        }
    }

    cout << ans << '\n';
}