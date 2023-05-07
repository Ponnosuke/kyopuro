// 配るDP

#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

const i64 INF = 1e15; 

int main() {
    int N;
    cin >> N;
    vector<i64> h(N+1,0);
    for(int i = 1; i <= N; i++)  cin >> h.at(i);

    vector<i64> dp(N+1, INF);
    dp.at(1) = 0;
    
    for(int i = 1; i <= N-1; i++){
        dp.at(i+1) = min(dp.at(i+1), dp.at(i) + abs(h.at(i) - h.at(i+1)));

        if(i < N-1){
            dp.at(i+2) = min(dp.at(i+2), dp.at(i) + abs(h.at(i) - h.at(i+2)));
        }
    }

    cout << dp.at(N) << endl;

    return 0;
}