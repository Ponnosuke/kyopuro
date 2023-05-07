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

i64 myRt2(i64 n2, i64 jokai){
    i64 NG = -1, OK = jokai;
    while(abs(OK - NG) > 1){
        i64 mid = OK + (NG - OK)/2;
        if(n2 <= mid*mid){
            OK = mid;
        }
        else{
            NG = mid;
        }
    }

    return OK;
}

int main() {
    i64 N;
    cin >> N;

    i64 Nrt2 = myRt2(N, 1000000 + 10);

    debugVL(Nrt2);

    vector<i64> primes;
    vector<bool> isPrime(Nrt2 + 1, true);
    isPrime.at(0) = false;
    isPrime.at(1) = false;
    for(i64 i = 2; i <= Nrt2; i++){
        if(!isPrime.at(i)){
            continue;
        }

        primes.push_back(i);

        for(i64 j = i*2; j <= Nrt2; j += i){
            isPrime.at(j) = false;
        }
    }


    i64 pSize = primes.size();
    i64 cnt = 0;

    debugVL(pSize);

    for(int i = 0; i < pSize; i++){
        for(int j = i+1; j < pSize; j++){
            if(primes.at(i)*primes.at(i)*primes.at(j) > N){
                break;
            }
            for(int k = j+1; k < pSize; k++){
                if(primes.at(i)*primes.at(j)*primes.at(k) > N){
                    break;
                }
                if(primes.at(i)*primes.at(i)*primes.at(j)*primes.at(k) > N){
                    break;
                }
                i64 judge = primes.at(i)*primes.at(i)*primes.at(j)*primes.at(k)*primes.at(k);
                if(judge <= N){
                    cnt++;
                }
                else{
                    break;
                }
            }
        }
    }

    cout << cnt << endl;

}