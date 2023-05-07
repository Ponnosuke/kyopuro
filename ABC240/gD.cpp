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
// myRnd32() よりこっちの方が高速な可能性が高い(ローカルでもAtCoderオンラインコンパイルでも)。
// [L, R] を満たす int64_t 型のランダムな整数を返す
// ただし、 mt19937_64 は uint64_t 型を返していることに注意
i64 myRnd64(i64 L, i64 R){
    random_device seedGen;
    mt19937_64 rd(seedGen());

    i64 ret = L + (rd() % (R - L + 1));

    return ret;
}

int main() {
    int N = 10;
    vector<int> a(N);
    for(int i = 0; i < N; i++){
        // a.at(i) = myRnd64(2, 5);
        a.at(i) = 2;
    }

    cout << N << '\n';
    for(int i = 0; i < N; i++){
        cout << a.at(i);

        if(i < N-1){
            cout << " ";
        }
    }
    cout << '\n';
}