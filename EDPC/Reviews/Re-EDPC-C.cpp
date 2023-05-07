// This is WA.

#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

const i64 INF = 1e15;

int main() {
    i64 N;
    cin >> N;
    vector<i64> a(N), b(N), c(N);
    for(int i = 0; i < N; i++)  cin >> a.at(i) >> b.at(i) >> c.at(i);

    vector<vector<i64>> dp(N+1010, vector<i64>(3, 0));
    // dp[i][j]
    // i日目時点で j を選んだ時の幸福度の総和の最大値
    // j  0:A  1:B  2:C

    for(int i = 0; i < N; i++){

        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                if(j == k)  continue;

                i64 tmp;
                if(k == 0)  tmp = a.at(i);
                else if(k == 1)  tmp = b.at(i);
                else  tmp = c.at(i);

                dp.at(i+1).at(k) = max(dp.at(i+1).at(k), dp.at(i).at(j) + tmp);
            }
        }

    }

    i64 ans = -1;
    for(int i = 0; i < 3; i++)  ans = max(ans, dp.at(N).at(i));

    cout << ans << endl;

    return 0;
}