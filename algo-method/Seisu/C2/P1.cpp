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

const int NUM = 30;

int main() {
    vector<bool> isFace(NUM + 1, true);
    for(int i = 2*2; i <= NUM; i += 2){
        isFace.at(i) = false;
    }
    for(int i = 3*2; i <= NUM; i += 3){
        isFace.at(i) = false;
    }

    vector<bool> isPrime(NUM + 1, true);
    isPrime.at(0) = false;
    isPrime.at(1) = false;
    for(int i = 2; i * i <= NUM; i++){
        if(!isPrime.at(i)){
            continue;
        }

        for(int a = i*2; a <= NUM; a += i){
            isPrime.at(a) = false;
        }
    }

    for(int i = 2; i <= NUM; i++){
        if(!isPrime.at(i) && isFace.at(i)){
            cout << i << endl;
            break;
        }
    }

    return 0;
}