#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    set<int> S;
    for(int i = 0; i < 5; i++){
        int tmp;
        cin >> tmp;
        S.insert(tmp);
    }

    // debug
    // for(auto x : S){
    //     cout << x << endl;
    // }

    int ans = S.size();

    cout << ans << endl;
}