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

i64 ceilRt3(i64 n2, i64 upperBound){

    assert(n2 >= 0);

    i64 NG = -1, OK = upperBound;
    while(abs(OK - NG) > 1){
        i64 mid = OK + (NG - OK)/2;
        if(n2 <= mid*mid*mid){
            OK = mid;
        }
        else{
            NG = mid;
        }

        debugV(OK);
        debugVL(NG);
    }

    return OK;
}

i64 floorRt3(i64 n, i64 upperBound){
    
    assert(n >= 0);
    
    i64 NG = -1, OK = upperBound;
    while(abs(OK - NG) > 1){
        i64 mid = OK + (NG - OK)/2;
        if(n <= mid*mid*mid){
            OK = mid;
        }
        else{
            NG = mid;
        }
    }

    if(OK*OK*OK > n){
        OK--;
    }

    return OK;
}

const i64 UPPER_BOUND_NUM = 1000000;

int main() {
    i64 N;
    cin >> N;

    i64 Nrt3 = floorRt3(N, UPPER_BOUND_NUM);
    vector<bool> isPrime(Nrt3 + 1, true);
    isPrime.at(0) = false;
    isPrime.at(1) = false;
    vector<i64> P;
    vector<i64> S(Nrt3 + 2, 0);
    for(i64 i = 2; i <= Nrt3; i++){
        if(!isPrime.at(i)){
            S.at(i+1) += S.at(i);
            continue;
        }

        P.push_back(i);
        S.at(i)++;
        S.at(i+1) += S.at(i);

        // j = i*2, i*3, ... i*(i-1)  は既に落とされているので見る必要がない
        for(i64 j = i*i; j <= Nrt3; j += i){
            isPrime.at(j) = false;
        }
    }

    debugP();

    int pSize = P.size();
    i64 cnt = 0;
    for(int i = 0; i < pSize; i++){
        i64 a = P.at(i);
        if(a*a*a*a >= N){
            break;
        }

        i64 b = floorRt3(N/a, UPPER_BOUND_NUM);
        if(b > a){
            cnt += (S.at(b) - S.at(a));
        }
    }

    cout << cnt << endl;
}