/*
    エラトステネスのふるい
    
    Q3. N 以下の素数の個数 https://algo-method.com/submissions/881801
*/

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

    vector<bool> isPrime(N+1, true);
    isPrime.at(0) = isPrime.at(1) = false;
    // isPrime を完成させるだけなら i*i <= N で良い。
    // 作りながら全素数を列挙するとかなら i <= N まで調べつつ vector に追加していく
    for(i64 i = 2; i * i <= N; i++){
        if(!isPrime.at(i)){
            continue;
        }

        // i64 j = i*2 でも良い。
        // i*2, i*3, ... i*(i-1) はすでにふるい落とされているため見る必要がない
        for(i64 j = i*i; j <= N; j += i){
            isPrime.at(j) = false;
        }
    }

    i64 cnt = 0;
    for(i64 i = 0; i <= N; i++){
        if(isPrime.at(i)){
            cnt++;
        }
    }

    cout << cnt << endl;
}