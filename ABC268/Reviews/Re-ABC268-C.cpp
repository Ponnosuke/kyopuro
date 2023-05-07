#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

const int INF = 1e7;

int main() {
    int N;
    cin >> N;
    vector<int> p(N, 0);
    for(auto &x : p)  cin >> x;

    vector<int> cnt(N, 0);
    for(int i = 0; i < N; i++){
        int j = ((((p.at(i) - 1) - i) % N) + N ) % N;

        for(int k = 0; k < 3; k++){
            cnt.at((j + k) % N )++;
        }
    }

    int ans = -INF;
    for(auto x : cnt)  ans = max(ans, x);

    cout << ans << endl;
}