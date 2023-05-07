// 累積和を用いた解法

#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

const i64 mod1 = 1e9 + 7;

int main() {
    i64 N;
    cin >> N;

    vector<i64> A(N);
    vector<i64> B(N+1);  // 累積和テーブル用
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
        B.at(i+1) = A.at(i) + B.at(i);
    }

    i64 ans = 0;
    i64 sum = 0;
    for(int i = 0; i < N - 1; i++){
        sum = B.at(N) - B.at(i+1);  // sum は最大 2 * 10^14 ほどになる。累積和なので負の心配はない。
        sum %= mod1;
        ans += (A.at(i) * sum);  // 最大 10^9 * (10^9 + 6)。 int64_t に収まる
        ans %= mod1;
    }

    cout << ans << endl;
}