/*
    The original of this code is written by spihill.
    I edited the code a little.
    
*/

#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    i64 N, M;
    cin >> N >> M;
    
    vector<pair<i64, i64>> v(N);
    for(int i = 0 ; i < N; i++){
        cin >> v.at(i).first >> v.at(i).second;
    }

    sort(v.begin(), v.end());
    
    i64 ans = 0;
    for(auto [a, b]: v){
        i64 t = min(M, b);
        M -= t;
        ans += t * a;
    }
    cout << ans << endl;
}