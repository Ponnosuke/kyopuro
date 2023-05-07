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

    i64 cnt = 1;
    for(i64 i = 2; i*i <= N; i++){
        i64 tmp = 0;
        while(N % i == 0){
            N /= i;
            tmp++;
        }

        if(tmp > 0){
            cnt++;
        }
    }
    if(N > 1){
        cnt++;
    }

    cout << cnt << endl;
}