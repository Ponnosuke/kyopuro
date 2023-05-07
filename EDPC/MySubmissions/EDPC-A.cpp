#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N;
    cin >> N;
    vector<int> h(N+1, 0);
    for(int i = 1; i <= N; i++)  cin >> h.at(i);

    vector<int> dp(N+1, 0);
    dp.at(2) = abs(h.at(2) - h.at(1));

    for(int i = 3; i <= N; i++){
        dp.at(i) = min(dp.at(i-1) + abs(h.at(i) - h.at(i-1)), dp.at(i-2) + abs(h.at(i) - h.at(i-2)));
    }

    cout << dp.at(N) << endl;

    return 0;
}