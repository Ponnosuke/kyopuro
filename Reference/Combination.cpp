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
    以下より引用

    組み合わせ(nCr)をC++で実装して時間計測 - Qiita 
    https://qiita.com/mosamosa/items/79cf230ae22ee71f6801 
*/
std::vector<std::vector<long long>> comb(int n, int r) {
    std::vector<std::vector<long long>> v(n + 1,std::vector<long long>(n + 1, 0));
    for (int i = 0; i < v.size(); i++) {
        v[i][0] = 1;
        v[i][i] = 1;
    }
    for (int j = 1; j < v.size(); j++) {
        for (int k = 1; k < j; k++) {
        v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
        }
    }
    return v;
}

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

// up の部分がオーバーフローしやすいので注意。本番とかではcomb64 を使うのが良さそう
i64 nCr(i64 n, i64 r){
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
    i64 N, M;
    cin >> N >> M;

    cout << comb64(N, M) << endl;
}