#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

const i64 INF = 1e17;

int main() {
    i64 N;
    cin >> N;
    vector<i64> a(N+1);
    for(int i = 1; i <= N; i++)  cin >> a.at(i);

    vector<i64> dp(N+1, INF);  // dp[i]  i本目にいるとき、かかっている最小コスト
    dp.at(0) = 0;
    dp.at(1) = 0;
    dp.at(2) = abs(a.at(2) - a.at(1));
    for(i64 i = 2; i < N; i++){
        dp.at(i+1) = min(dp.at(i) + abs(a.at(i+1) - a.at(i)), dp.at(i-1) + abs(a.at(i+1) - a.at(i-1)));
    }

    cout << dp.at(N) << endl;
}