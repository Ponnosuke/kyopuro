#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    i64 N, M;
    cin >> N >> M;

    vector<pair<i64, i64>> AB(N);  // (A, B)
    for(int i = 0; i < N; i++){
        i64 a, b;
        cin >> a >> b;

        AB.at(i) = make_pair(a, b);
    }

    sort(AB.begin(), AB.end());

    // debug
    /*
    for(auto x:AB){
        cout << x.first << " " << x.second << endl;
    }
    */

    i64 ans = 0, cnt = 0, index = 0;
    while(cnt < M){
        ans += AB.at(index).first;
        AB.at(index).second--;
        cnt++;

        if(AB.at(index).second <= 0){
            index++;
        }
    }

    cout << ans << endl;
}