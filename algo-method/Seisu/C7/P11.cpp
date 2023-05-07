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

i64 primeCnt(i64 n, i64 p){
    i64 ret = 0;
    while(n){
        ret += (n/p);
        n /= p;
    }

    return ret;
}

int main() {
    i64 N;
    cin >> N;

    i64 a = primeCnt(N, 2), b = primeCnt(N, 5);

    cout << min(a, b) << endl;
}