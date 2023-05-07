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
    i64 N;
    cin >> N;

    vector<bool> isPrime(100000, true);
    isPrime.at(0) = isPrime.at(1) = false;
    i64 cnt = 0;
    for(i64 i = 2; i*i <= N; i++){
        if(!isPrime.at(i)){
            continue;
        }

        cnt++;
        for(i64 j = i*i; j*j <= N; j += i){
            isPrime.at(j) = false;
        }
    }

    cout << cnt << endl;
}