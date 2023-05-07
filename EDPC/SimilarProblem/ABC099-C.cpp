#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

const i64 INF = 1e17;

int main() {
    int N;
    cin >> N;

    vector<i64> dp(N+100, INF); // dp[i] i円出すのに必要な最小操作回数
    dp.at(0) = 0;

    // 1 yen
    for(int i = 0; i <= N; i++){
        dp.at(i) = i;
    }

    // debug
    i64 count6 = 0, count9 = 0;

    for(int i = 1; i <= N; i++){
        // 6 yen  // O(logN) ?
        for(int now = 1; now <= i; now *= 6){
            dp.at(i) = min(dp.at(i), dp.at(i - now) + 1);

            // debug
            count6++;

        }

        // 9 yen
        for(int now = 1; now <= i; now *= 9){
            dp.at(i) = min(dp.at(i), dp.at(i - now) + 1);

            // debug
            count9++;
            
        }
    }

    // debug
    cout << "N = " << N << endl;
    cout << "count6 = " << count6 << endl;
    cout << "count9 = " << count9 << endl;

    cout << dp.at(N) << endl;
}