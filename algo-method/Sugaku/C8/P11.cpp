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

i64 nPr(i64 n, i64 r){
    if(n < r){
        return 0;
    }

    i64 ret = 1;

    for(i64 i = n; i > n-r; i--){
        ret *= i;
    }

    return ret;
}

i64 nCr(i64 n, i64 r){
    // if(n > (n-r)){
    //     r = (n-r);
    // }

    if(r > (n-r)){
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
    int N, M, p;
    cin >> N >> M >> p;

    double ans = 1.0;
    for(int i = 0; i < M; i++){
        ans *= (double)p / 100.0;
    }
    for(int i = M; i < N; i++){
        ans *= (double)(100 - p) / 100.0;
    }
    ans *= nCr(N, M);

    cout << fixed << setprecision(18);
    cout << ans << endl;

    return 0;
}