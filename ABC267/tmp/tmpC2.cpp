// 恐らく TLE を起こす

#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

const i64 INF = 1e17;

int main() {
    int N, M;
    cin >> N >> M;
    vector<i64> A(N);
    for(auto &x : A)  cin >> x;

    i64 ans = -INF;
    for(int i = 0; i <= (N - M); i++){
        i64 sum = 0;
        for(int j = 0; j < M; j++){
            sum += (j+1) * A.at(j + i);
        }
        ans = max(ans, sum);
    }

    cout << ans << endl;
}