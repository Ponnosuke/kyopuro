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

ui64 Solver1(ui64 N){
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

    return ans;
}

ui64 Solver2(ui64 N){

    // debugWL(point76);

    vector<ui64> primes;

    vector<bool> isPrime(N+1, true);
    isPrime[0] = false;
    isPrime[1] = false;

    // debugWL(point80);

    for(ui64 a = 2; a <= N; a++){
        if(!isPrime[a]){
            continue;
        }

        for(ui64 i = (a+a); i <= N; i += a){
            isPrime[i] = false;
        }
    }

    // debugWL(point89);

    for(ui64 i = 0; i <= N; i++){
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

    return ans;

}

i64 myRnd64(i64 L, i64 R){
    random_device seedGen;
    mt19937_64 rd(seedGen());

    i64 ret = L + (rd() % (R - L + 1));

    return ret;
}

const ui64 LOOP = 100;

int main() {

    debugWL(start);

    for(ui64 i = 0; i < LOOP; i++){
        ui64 N = myRnd64(1, 100000);
        // debugVL(N);

        ui64 solve1 = Solver1(N);

        // debugV(solve1);

        ui64 solve2 = Solver2(N);

        // debugVL(solve2);

        if(solve1 != solve2){
            debugWL(wrong!);
            debugVL(N);
            debugV(solve1);
            debugVL(solve2);

            break;
        }

        if(i % 10 == 0){
            debugVL(i);
        }
    }

    debugWL(finish);

    return 0;
}