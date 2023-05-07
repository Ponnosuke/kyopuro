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

ui64 nCr(ui64 n, ui64 r){
    debugV(n);
    debugV(r);
    debugVL(n-r);

    if(r > (n-r)){
        r = (n-r);
    }

    debugV(n);
    debugVL(r);

    ui64 up = 1;
    for(ui64 i = 0; i < r; i++){
        debugV(i);
        debugVL(n-i);

        up *= (n-i);

        debugVL(up);
        debugWL();
    }
    ui64 down = 1;
    for(ui64 i = r; i >= 1; i--){
        down *= i;
    }

    debugWL();

    return up / down;
}

// n種類の中から重複を許して r 個選ぶ方法の通り数
i64 nHr(i64 n, i64 r){
    return nCr(r+n-1, r);
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

int main() {
    ui64 N, K;
    cin >> N >> K;

    i64 nume1 = comb64(N-1, K-1), deno1 = comb64(N, K);
    ui64 nume2 = nCr(N-1, K-1), deno2 = nCr(N, K);
    debugV(nume1);
    debugVL(deno1);
    debugV(nume2);
    debugVL(deno2);

    cout << fixed << setprecision(19);
    cout << (double)nume1 / (double)deno1 << endl;

}