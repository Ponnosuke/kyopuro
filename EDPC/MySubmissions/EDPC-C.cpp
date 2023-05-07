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

    vector<i64> dp(N + 1010, -INF);  // i 日目時点での総和の最大値
    dp.at(0) = 0;

    int aCnt = 0, bCnt = 0, cCnt = 0;
    for(int i = 0; i < N; i++){
        int tmpA = aCnt, tmpB = bCnt, tmpC = cCnt;

        // debug
        // cout << "Loop"  << i << endl;
        // cout << "before" << endl;
        // cout << "aCnt bCnt cCnt" << endl;
        // cout << aCnt << " " << bCnt << " " << cCnt << endl;

        if(aCnt < 1){
            if(dp.at(i+1) < dp.at(i) + a.at(i)){
                dp.at(i+1) = dp.at(i) + a.at(i);
                tmpA = aCnt + 1;
                tmpB = 0;
                tmpC = 0;
            }

            // debug
            // cout << "routeA1" << endl;
        }
        else{
            aCnt = 0;
        }

        if(bCnt < 1){
            if(dp.at(i+1) < dp.at(i) + b.at(i)){
                dp.at(i+1) = dp.at(i) + b.at(i);
                tmpA = 0;
                tmpB = bCnt + 1;
                tmpC = 0;
            }

            // debug
            // cout << "routeB1" << endl;
        }
        else{
            bCnt = 0;
        }

        if(cCnt < 1){
            if(dp.at(i+1) < dp.at(i) + c.at(i)){
                dp.at(i+1) = dp.at(i) + c.at(i);
                tmpA = 0;
                tmpB = 0;
                tmpC = cCnt + 1;
            }

            // debug
            // cout << "routeC1" << endl;
        }
        else{
            cCnt = 0;
        }

        aCnt = tmpA;
        bCnt = tmpB;
        cCnt = tmpC;

        // debug
        // cout << "after" << endl;
        // cout << "aCnt bCnt cCnt" << endl;
        // cout << aCnt << " " << bCnt << " " << cCnt << endl << endl;
    }

    // debug
    // for(int i = 0; i <= N; i++)  cout << "dp.at(" << i << ") = " << dp.at(i) << endl;

    cout << dp.at(N) << endl;

    return 0;
}