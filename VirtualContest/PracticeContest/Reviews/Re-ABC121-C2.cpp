#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N;
    i64 M;
    cin >> N >> M;

    vector<pair<i64, i64>> v(N);  // (A, B)

    for(int i = 0; i < N; i++){
        i64 a, b;
        cin >> a >> b;
        v.at(i) = make_pair(a, b);
    }

    sort(v.begin(), v.end());

    i64 ans = 0, cnt = 0;
    for(auto [a, b] : v){
        i64 tmp = min(M - cnt, b);
        ans += a * tmp;
        cnt += tmp;

        if(cnt >= M)  break;
    }

    cout << ans << "\n";
}