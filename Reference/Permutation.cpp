/*
do-while 文を使う主な場面。順列を全部列挙する
*/

/*
next_permutation関数は、
「区別可能なn個の対象から重複を許してk個の対象を取り出して特定の順番で並べたもの」
を全列挙するための関数。
事前にsortが必要なことに注意。また、計算量は
配列の長さを N として O(N!)
*/

// 使い方
/*

sort(配列変数.begin(), 配列変数.end());
do {
  // 順列に対する処理
} while (next_permutation(配列変数.begin(), 配列変数.end()));

*/

#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    vector<int> v = {2, 1, 3};
    sort(v.begin(), v.end());
    do{
        // 1行で今の並び方を出力
        for(int x : v){
            cout << x << " ";
        }
        cout << endl;
    } while (next_permutation(v.begin(), v.end()));
}

/*
1 2 3 
1 3 2 
2 1 3 
2 3 1 
3 1 2 
3 2 1 
*/