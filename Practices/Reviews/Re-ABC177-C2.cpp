// AC
// 通らなかった原因は sum が負の数になる場合を考えていなかったことっぽい

#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

const i64 mod1 = 1e9 + 7;

int main() {
    i64 N;
    cin >> N;

    vector<i64> A(N);
    for(auto &x : A)  cin >> x;

    i64 sum = 0;
    for(auto x : A){
        sum += x;
        sum %= mod1;
    }

    i64 ans = 0;
    for(i64 i = 0; i < N; i++){
        sum -= A.at(i);
        if(sum < 0) sum += mod1;  // sum が負の数になる可能性をしっかり考慮する
        
        ans += A.at(i) * sum;  
        // max は 10^9 * (10^9 + 6) = 10^18 + 6 * 10^9  なんとか int64_t に収まる
        // int64_t の最大値は 2^63 - 1 = 9.2 * 10^18 くらい
        ans %= mod1;
    }

    cout << ans << endl;

    return 0;
}