/*
char と string を + すると、連結をできる。
*/

#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    string str = "Hello";

    char c = str.at(0);  // 一文字は char 型で取り出される
    cout << str + c << endl; // HelloH
}
