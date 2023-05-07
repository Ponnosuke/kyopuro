#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    i64 N;
    cin >> N;

    map<i64, i64> cnt;
    for(i64 i = 0; i < N; i++){
        i64 A;
        cin >> A;

        cnt[A]++;
    }

    i64 ans = 0;
    for(auto p1 : cnt){
        for(auto p2 : cnt){
            i64 i = p1.first, j = p2.first;
            i64 cnt1 = p1.second, cnt2 = p2.second;
            ans += (i - j)*(i - j) * cnt1 * cnt2;
        }
    }
    ans /= 2;

    cout << ans << endl;

    return 0;
}