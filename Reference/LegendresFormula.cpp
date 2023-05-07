/*
    ルジャンドルの定理

    解説 - デンソークリエイトプログラミングコンテスト2022 Winter(AtCoder Beginner Contest 280) 
    https://atcoder.jp/contests/abc280/editorial/5348 

    N! の約数の個数 | アルゴ式 
    https://algo-method.com/tasks/452/editorial 
*/

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

// n! が 素数 p で何回割り切れるかを返す
// つまり n! を素因数分解したとき p は何乗になるか
i64 LegendreFunc(i64 n, i64 p){
    i64 ret = 0;
    while(n > 0){
        ret += (n / p);
        n /= p;
    }

    return ret;
}

/*

i64 LegendreFunc2(i64 n, i64 p){
    i64 ret = 0;
    while(n / p > 0){
        ret += (n / p);
        n /= p;
    }

    return ret;
}

*/
int main() {
    cout << LegendreFunc(100, 2) << endl;
}