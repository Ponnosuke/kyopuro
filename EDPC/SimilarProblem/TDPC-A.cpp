#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

const i64 INF = 1e17;

int main() {
    int N;
    cin >> N;
    vector<i64> p(N, 0);
    i64 sumP = 0;
    for(int i = 0; i < N; i++){
        i64 tmp;
        cin >> tmp;

        p.at(i) = tmp;
        sumP += tmp;
    }

    vector<vector<bool>> dp(N + 1, vector<bool>(sumP + 1, false));
    // dp[i][j]  p_(i-1) までを選択対象としたとき (i個のpから選ぶとき)、j点を取れるか否か
    dp.at(0).at(0) = true;

    for(int i = 0; i < N; i++){
        for(int j = 0; j <= sumP; j++){
            if(dp.at(i).at(j)) dp.at(i + 1).at(j) = true;

            if(j - p.at(i) >= 0){
                if(dp.at(i).at(j-p.at(i)))  dp.at(i+1).at(j) = true;
            }
        }
    }

    i64 ans = 0;
    for(int j = 0; j <= sumP; j++){
        if(dp.at(N).at(j))  ans++;
    }

    cout << ans << endl;
}