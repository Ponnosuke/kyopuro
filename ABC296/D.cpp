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

i64 myUpSqrt(i64 n2, i64 jokai){
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

const i64 POW6 = 1000000;

bool isOK(i64 N, i64 num){
    bool OK = false;
    for(i64 i = 1; i*i <= num; i++){
        if(num % i != 0){
            continue;
        }

        i64 i2 = (num/i);

        debugV(i);
        debugVL(i2);
        if(i <= N && i2 <= N){
            OK = true;
            break;
        }
    }

    return OK;
}

int main() {
    i64 N, M;
    cin >> N >> M;

    if(M % N == 0){
        if(M/N == N){
            cout << M << '\n';
            return 0;
        }
    }

    if((M/N) >= N){
        cout << -1 << '\n';
        return 0;
    }

    i64 up = myUpSqrt(M, POW6);
    i64 up2 = up*up;
    debugV(up);
    debugVL(up2);
    for(i64 i = M; i < up2; i++){
        debugVL(i);
        if(isOK(N, i)){
            debugP();
            cout << i << '\n';
            return 0;
        }
    }

    cout << up2 << '\n';

    return 0;
}