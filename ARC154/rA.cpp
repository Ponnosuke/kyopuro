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

const i64 MOD = 998244353;

int main() {
    int N;
    cin >> N;
    string A, B;
    cin >> A >> B;

    for(int i = 0; i < N; i++){
        int numA = A.at(i) - '0', numB = B.at(i) - '0';

        if(numA > numB){
            swap(A.at(i), B.at(i));
        }
    }

    i64 numA = 0, numB = 0;
    for(int i = 0; i < N; i++){
        numA *= 10;
        numB *= 10;
        numA %= MOD;
        numB %= MOD;

        numA += (i64)(A.at(i) - '0');
        numB += (i64)(B.at(i) - '0');

        numA %= MOD;
        numB %= MOD;
    }

    cout << (numA * numB) % MOD << endl;
}