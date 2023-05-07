/*
cin は 空白や改行区切りの入力を簡単に扱える。
一方で、空白で区切らずに行単位で入力を受け取りたい場合 getline を使う
*/

/*
getline(cin, 文字列変数);
getline は function
*/

#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    string s, t;
    getline(cin, s); // 変数 s で入力を一行受け取る
    getline(cin, t); // 変数t で入力を一行受け取る
// 入力
/*
I have a pen.
I have an apple.
*/


    cout << "一行目 " << s << endl;  // 一行目 I have a pen.
    cout << "二行目 " << t << endl;  // 二行目 I have an apple.
}
