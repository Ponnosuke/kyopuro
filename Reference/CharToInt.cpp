/*
A - Lacked Number 
https://atcoder.jp/contests/abc248/tasks/abc248_a 
*/

#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    set<int> S;
    for(int i = 0; i < 9; i++){
        char ch;
        cin >> ch;  // string を一文字ずつ入力
        S.insert(ch - '0');  // char to int
    }

    for(int i = 0; i <= 9; i++){
        if(!S.count(i)){
            cout << i << endl;
        }
    }
}