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

/*
    以下より引用したものを編集
    i64 nCr を返す

    組み合わせ(nCr)をC++で実装して時間計測 - Qiita 
    https://qiita.com/mosamosa/items/79cf230ae22ee71f6801 
*/
i64 comb64(int n, int r) {
    std::vector<std::vector<i64>> v(n + 1,std::vector<i64>(n + 1, 0));
    for (int i = 0; i < v.size(); i++) {
        v[i][0] = 1;
        v[i][i] = 1;
    }
    for (int j = 1; j < v.size(); j++) {
        for (int k = 1; k < j; k++) {
        v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
        }
    }
    return v[n][r];
}

int main() {
    int X, Y;
    cin >> X >> Y;

    cout << fixed << setprecision(18);
    cout << (double)X / (double)(X+Y) << endl;

    return 0;
}