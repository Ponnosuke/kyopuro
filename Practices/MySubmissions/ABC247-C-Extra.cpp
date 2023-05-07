/*
    フィボナッチ数列
    メモ化再帰
*/

#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

map<i64, i64> memo;

i64 func(i64 n){
    if(n == 0){
        memo[n] = 0;
        return 0;
    }
    if(n == 1){
        memo[n] = 1;
        return 1;
    }

    if(memo.count(n)){
        return memo.at(n);
    }

    i64 ret = func(n-1) + func(n-2);
    memo[n] = ret;

    return ret;
}

int main() {
    i64 n;
    cin >> n;

    cout << func(n) << "\n";
}