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

// n! を 素数pで何回割り切れるか
i64 PrimeDivCnt(i64 n, i64 p){
    i64 ret = 0;
    while(n > 0){
        ret += (n / p);
        n /= p;
    }

    return ret;
}

int main() {
    i64 N;
    cin >> N;

    vector<bool> isPrime(N + 1, true);
    isPrime[0] = isPrime[1] = false;

    vector<i64> cnts;
    for(i64 i = 2; i <= N; i++){
        if(!isPrime.at(i)){
            continue;
        }

        for(i64 j = i*i; j <= N; j += i){
            isPrime.at(j) = false;
        }

        cnts.push_back(PrimeDivCnt(N, i));
    }

    i64 ans = 1;
    for(i64 i = 0; i < cnts.size(); i++){
        ans *= (cnts.at(i) + 1);
    }

    cout << ans << endl;
}