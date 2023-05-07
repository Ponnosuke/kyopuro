#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

const int INF = 1000000;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(auto &x : A)  cin >> x;

    int ans = INF;
    for(auto x : A){
        ans = min(ans, x);
    }

    cout << ans << endl;
}