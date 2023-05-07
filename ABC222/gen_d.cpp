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
    int N = 3000;
    int a = 0, b = 3000;
    
    cout << N << '\n';
    for(int i = 0; i < N; i++){
        cout << a;
        if(i < N-1){
            cout << " ";
        }
    }
    cout << '\n';
    for(int i = 0; i < N; i++){
        cout << b;
        if(i < N-1){
            cout << " ";
        }
    }
    cout << '\n';

    return 0;
}