#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N;
    cin >> N;
    i64 D;
    cin >> D;

    int twoCnt = 0, threeCnt = 0, fiveCnt = 0;
    while(D % 2 == 0){
        D /= 2;
        twoCnt++;
    }
    while(D % 3 == 0){
        D /= 3;
        threeCnt++;
    }
    while(D % 5 == 0){
        D /= 5;
        fiveCnt++;
    }

    // debug
    // cout << twoCnt << " " << threeCnt << " " << fiveCnt << endl;

    if(D > 1){
        cout << 0 << endl;
    }
    else{
        vector<vector<vector<vector<double>>>> dp(N + 1, vector<vector<vector<double>>>(twoCnt + 1, vector<vector<double>>(threeCnt + 1, vector<double>(fiveCnt + 1, 0))));
        // dp[i][j][k][l]  i回ふった時に、2, 3, 5 がそれぞれ j, k, l 個含まれている確率
        dp.at(0).at(0).at(0).at(0) = 1.0;
    
        // 配るDP
        for(int i = 0; i < N; i++){
            for(int j = 0; j <= twoCnt; j++){
                for(int k = 0; k <= threeCnt; k++){
                    for(int l = 0; l <= fiveCnt; l++){

                        // debug
                        // cout << i << j << k << l << endl;

                        double p = dp.at(i).at(j).at(k).at(l) / 6.0;

                        // debug
                        // cout << i << j << k << l << endl;

                        // twoCnt, threeCnt, fiveCnt より多くなるケースは統合する
                        dp.at(i+1).at(j).at(k).at(l) += p; // 1

                        // debug
                        // cout << "one: " << i << j << k << l << endl;

                        dp.at(i+1).at(min(j+1, twoCnt)).at(k).at(l) += p; // 2

                        // debug
                        // cout << "two: " << i << j << k << l << endl;

                        dp.at(i+1).at(j).at(min(k+1, threeCnt)).at(l) += p; // 3

                        // debug
                        // cout << "three: " << i << j << k << l << endl;

                        dp.at(i+1).at(min(j+2, twoCnt)).at(k).at(l) += p; // 4

                        // debug
                        // cout << "four: " << i << j << k << l << endl;

                        dp.at(i+1).at(j).at(k).at(min(l+1, fiveCnt)) += p; // 5

                        // debug
                        // cout << "five: " <<  i << j << k << l << endl;

                        dp.at(i+1).at(min(j+1, twoCnt)).at(min(k+1, threeCnt)).at(l) += p; //6

                        // debug
                        // cout << "six: " << i << j << k << l << endl;

                        // debug
                        // cout << i << j << k << l << endl;
                    }
                }
            }
        }

        cout << fixed << setprecision(15);
        cout << dp.at(N).at(twoCnt).at(threeCnt).at(fiveCnt) << endl;        
    }
}