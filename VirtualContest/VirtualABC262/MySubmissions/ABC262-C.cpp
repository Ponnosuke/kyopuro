/*
    Wrong Answer
*/


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

    int diffCnt = 0, sameCnt = 0;

    for(int i = 1; i <= N; i++){
        if(a.at(i) == i){
            sameCnt++;
            continue;
        }

        if(i == a.at(a.at(i))) diffCnt++;
    }

    // debug
    // cout << sameCnt << " " << diffCnt << endl;

    int ans = diffCnt/2 + (sameCnt*(sameCnt - 1))/2;
    // ans の最大数が O(10^10) くらいいくので int型を超える

    cout << ans << endl;
}