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

i64 floorSqrt(i64 n, i64 upperBound){
    
    assert(n >= 0);
    
    i64 NG = -1, OK = upperBound;
    while(abs(OK - NG) > 1){
        i64 mid = OK + (NG - OK)/2;
        if(n <= mid*mid){
            OK = mid;
        }
        else{
            NG = mid;
        }
    }

    if(OK*OK > n){
        OK--;
    }

    return OK;
}

int main() {
    i64 N;
    cin >> N;

    i64 Nrt2 = floorSqrt(N, 1000000 + 10);

    debugVL(Nrt2);

    vector<i64> primes;
    vector<bool> isPrime(Nrt2 + 1, true);
    isPrime.at(0) = false;
    isPrime.at(1) = false;
    vector<i64> S(Nrt2 + 2, 0);
    for(i64 i = 2; i <= Nrt2; i++){
        if(!isPrime.at(i)){
            S.at(i+1) += S.at(i);
            continue;
        }

        // debugP();

        S.at(i)++;
        S.at(i+1) += S.at(i);

        // debugP();

        primes.push_back(i);

        for(i64 j = i*2; j <= Nrt2; j += i){
            isPrime.at(j) = false;
        }
    }

    // debugP();


    i64 pSize = primes.size();
    i64 cnt = 0;
    debugVL(pSize);
    for(int i = 0; i < pSize; i++){
        i64 a = primes.at(i);
        if(a*a*a*a*a >= N){
            break;
        }
        for(int j = i+1; j < pSize; j++){
            i64 b = primes.at(j);
            if(b*b*b >= N){
                break;
            }


            i64 D = floorSqrt(N/a/a/b, 1000000 + 10);

            debugV(a);
            debugV(b);
            debugVL(D);
            debugV(S.at(D));
            debugVL(S.at(b));

            if(b < D){
                cnt += (S.at(D) - S.at(b));
            }
        }
    }

    cout << cnt << endl;

}