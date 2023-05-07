/*
    フィボナッチ数列
    動的計画法
*/

#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    i64 N;
    cin >> N;

    vector<i64> dp(N+1);

    dp.at(0) = 0;
    dp.at(1) = 1;

    for(int i = 2; i <= N; i++){
        dp.at(i) = dp.at(i-1) + dp.at(i-2);
    }

    cout << dp.at(N) << endl;
}