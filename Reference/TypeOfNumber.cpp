/*
    reference: "https://atcoder.jp/contests/apg4b/tasks/APG4b_y"


    int型は 2*10^9 (20億) くらいまで。それより大きかったら int64_t 型を使う。
    リテラルで 10 とだけ書くとそれは int 型の数値として扱われる
    リテラルで int64_t 型として扱ってほしかったら 10LL のように末尾に LL をつける。

*/

#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    cout << 2000000000 * 2 << endl;     // int * int         -> int
    cout << 2000000000LL * 2LL << endl; // int64_t * int64_t -> int64_t
    cout << 2000000000LL * 2 << endl;   // int64_t * int     -> int64_t
}