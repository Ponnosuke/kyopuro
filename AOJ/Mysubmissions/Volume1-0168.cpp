#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

const i64 YEAR = 365;

int main() {
    while(true){
        int n;
        cin >> n;
        if(n == 0)  break;

        vector<i64> dp(n+10, 0);  // dp[i]  i段目にのぼる方法の数
        dp.at(0) = 1;
        for(int i = 0; i < n; i++){
            dp.at(i+1) += dp.at(i);
            dp.at(i+2) += dp.at(i);
            dp.at(i+3) += dp.at(i);
        }

        i64 days = dp.at(n) / 10;
        if(dp.at(n) % 10 > 0)  days++;
        i64 ans = days / YEAR;
        if(days % YEAR > 0) ans++;

        cout << ans << endl;
    }

    return 0;
}