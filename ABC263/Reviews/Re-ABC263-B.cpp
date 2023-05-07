#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N;
    cin >> N;
    vector<int> P(N+1);
    for(int i = 2; i <= N; i++)  cin >> P.at(i);

    vector<int> dp(N+1);  // dp(i)  人 1 は 人i の何代前か
    dp.at(1) = 0;

    for(int i = 2; i <= N; i++){
        dp.at(i) = dp.at(P.at(i)) + 1;
    }

    cout << dp.at(N) << endl;
}