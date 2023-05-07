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
    i64 A;
    cin >> A;

    i64 N = 1;
    for(i64 i = 2; i*i <= A; i++){
        if(A % i != 0){
            continue;
        }

        i64 cnt = 0;
        while(A % i == 0){
            cnt++;
            A /= i;
        }

        if(cnt % 2 != 0){
            N *= i;
        }
    }
    if(A != 1){
        N *= A;
    }

    cout << N << endl;
}