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

i64 nCr(i64 n, i64 r){
    if(n > (n-r)){
        r = (n-r);
    }

    i64 up = 1;
    for(i64 i = 0; i < r; i++){
        up *= (n-i);
    }
    i64 down = 1;
    for(i64 i = r; i >= 1; i--){
        down *= i;
    }

    return up / down;
}

// n種類の中から重複を許して r 個選ぶ方法の通り数
i64 nHr(i64 n, i64 r){
    return nCr(r+n-1, r);
}

int main() {
    i64 N, M;
    cin >> N >> M;
    cout << nCr(N+M, N) << endl;
}