/*
Conditional (ternary) operator
条件演算子　または　三項演算子
*/

#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int a, b;
    cin >> a >> b;

    int answer = a < b ? a : b;  // 小さいほうを代入

    cout << answer << endl;
}