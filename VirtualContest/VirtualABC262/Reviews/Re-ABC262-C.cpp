#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N;
    cin >> N;
    vector<int> a(N + 1);
    for(int i = 1; i <= N; i++){
        cin >> a.at(i);
    }

    i64 diffCnt = 0, sameCnt = 0;

    for(int i = 1; i <= N; i++){
        if(a.at(i) == i){
            sameCnt++;
            continue;
        }

        if(i == a.at(a.at(i))) diffCnt++;
    }

    // debug
    // cout << sameCnt << " " << diffCnt << endl;

    i64 ans = diffCnt/2 + (sameCnt*(sameCnt - 1))/2;  
    // 総数は最大で O(10^10) くらい
    // N_C_2   N(N-1)/2

    cout << ans << endl;
}