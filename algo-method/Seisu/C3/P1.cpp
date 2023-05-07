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

const int NUM = 56;

int main() {
    int cnt = 0;
    for(int i = 1; i*i <= NUM; i++){
        if(NUM % i != 0){
            continue;
        }

        cnt++;

        if(NUM/i != i){
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}