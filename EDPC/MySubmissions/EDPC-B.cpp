#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

const i64 INF = 1e15;

int main() {
    i64 N, K;
    cin >> N >> K;
    vector<i64> h(N + 10000, 0);  // 0-indexed
    for(int i = 0; i < N; i++)  cin >> h.at(i);

    // 0-indexed
    vector<i64> dp(N + 10000, INF);
    dp.at(0) = 0;
    for(int i = 0; i < N; i++){
        for(int j = 1; j <= K; j++){
            dp.at(i+j) = min(dp.at(i+j), dp.at(i) + abs(h.at(i) - h.at(i+j)));
        }
    }

    N--;
    cout << dp.at(N) << endl;
}