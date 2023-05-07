#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

const i64 MOD = 1000000007;

int main() {
    i64 N, M;
    cin >> N >> M;

    vector<i64> a(M+1);
    for(int i = 1; i <= M; i++)  cin >> a.at(i);

    vector<bool> isBroken(N+10, false);  // isBroken[i]  i段目が壊れているか否か
    for(int i = 1; i <= M; i++)  isBroken.at(a.at(i)) = true;

    vector<i64> dp(N+10, 0);  // dp[i]  i段目にたどりつくまでの移動方法の通り数
    dp.at(0) = 1;
    for(int i = 0; i <= N; i++){
        if((!isBroken.at(i)) && (!isBroken.at(i+1))){
            dp.at(i+1) += dp.at(i);
            dp.at(i+1) %= MOD;
        }
        if((!isBroken.at(i)) && (!isBroken.at(i+2))){
            dp.at(i+2) += dp.at(i);
            dp.at(i+2) %= MOD;
        }
    }

    // debug
    // for(int i = 0; i <= N; i++){
    //     cout << "isBroken.at(" << i << ") = " << (isBroken.at(i) ? "true" : "false")  << endl;
    // }
    // for(int i = 0; i <= N; i++)  cout << "dp.at(" << i << ") = " << dp.at(i) << endl;

    cout << dp.at(N) << endl;
}