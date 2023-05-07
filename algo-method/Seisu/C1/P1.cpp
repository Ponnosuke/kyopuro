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

const i64 NUM = 53;

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
    i64 i = NUM + 1;
    bool stop = false;
    while(!stop){
        if(isPrime(i)){
            cout << i << endl;
            return 0;
        }
        else{
            i++;
        }
    }

    return 0;
}