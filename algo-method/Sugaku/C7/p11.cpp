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
    i64 N, Xa, Xb;
    cin >> N >> Xa >> Xb;

    assert(Xa + Xb == N);

    if(Xa > Xb){
        swap(Xa, Xb);
    }

    // N_C_Xa
    i64 up = 1;
    for(i64 i = 0; i < Xa; i++){
        up *= (N-i);
    }
    i64 down = 1;
    for(i64 i = Xa; i >= 1; i--){
        down *= i;
    }

    cout << up / down << endl;
}