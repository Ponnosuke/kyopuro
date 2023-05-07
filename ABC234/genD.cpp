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

// i64乱数ジェネレーター
// [L, R] を満たす int64_t 型のランダムな整数を返す
// ただし、 mt19937_64 は uint64_t 型を返していることに注意
i64 myRnd64(i64 L, i64 R){
    random_device seedGen;
    mt19937_64 rd(seedGen());

    i64 ret = L + (rd() % (R - L + 1));

return ret;
}

const int UPPER_BOUND_NUM = 20;

int main() {
    int K = myRnd64(1, UPPER_BOUND_NUM);
    int N = myRnd64(K, UPPER_BOUND_NUM);

    int roopCnt = myRnd64(1, 1000);
    vector<int> P(N);
    for(int i = 0; i < N; i++){
        P.at(i) = i+1;
    }

    for(int rep = 0; rep < roopCnt; rep++){
        next_permutation(P.begin(), P.end());
    }

    cout << N << " " << K << '\n';

    for(int i = 0; i < N; i++){
        cout << P.at(i);

        if(i < N-1){
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}