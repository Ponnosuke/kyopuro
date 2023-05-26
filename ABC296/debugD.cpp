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

const i64 INF = (1LL << 60);

i64 solver1(i64 N, i64 M){
    if(N <= M/N){
        return -1;
    }

    i64 ans = INF;
    for(i64 a = 1; a*a - a + 1 <= M; a++){
        i64 b = (M + (a-1)) / a;
        if((1 <= b) && (b <= N)){
            ans = min(ans, a*b);
        }
    }

    if(ans == INF){
        return -1;
    }
    else{
        return ans;
    }
}

i64 solver2(i64 N, i64 M){
    if(M % N == 0){
        if(M/N == N){
            return M;
        }
    }

    if((M/N) >= N){
        return -1;
    }

    i64 X = INF;
    for(i64 i = 1; i <= N; i++){
        for(i64 j = 1; j <= N; j++){
            if(M <= i*j){
                X = min(X, i*j);
            }
        }
    }

    if(X == INF){
        return -1;
    }
    else{
        return X;
    }
}

// i64乱数ジェネレーター
// [L, R] を満たす int64_t 型のランダムな整数を返す
// ただし、 mt19937_64 は uint64_t 型を返していることに注意
i64 myRnd64(i64 L, i64 R){
    random_device seedGen;
    mt19937_64 rd(seedGen());

    i64 ret = L + (rd() % (R - L + 1));

return ret;
}

const int LOOP_CNT = 100;

int main() {

    for(int rep = 0; rep < LOOP_CNT; rep++){
        if(rep % 10 == 0){
            debugVL(rep);
        }

        i64 N = myRnd64(1, 1000000000000);
        i64 M = myRnd64(1, 1000000000000);

        i64 sol1 = solver1(N, M), sol2 = solver2(N, M);

        if(sol1 != sol2){
            debugWL(Wrong!);
            debugV(N);
            debugVL(M);
            debugV(sol1);
            debugVL(sol2);

            exit(1);
        }
    }

    return 0;
}