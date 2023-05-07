#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

const i64 mod1 = 1000000007;
// const i64 mod1 = 1e9 + 7;

int main() {
    i64 N;
    cin >> N;
    vector<i64> A(N + 1, 0);
    for(int i = 1; i <= N; i++)  cin >> A.at(i);

    sort(A.begin(), A.end());

    i64 ans = 1;
    for(int i = N; i > 0 ; i--){
        ans *= A.at(i) - A.at(i-1) + 1;
        ans %= mod1;
    }

    cout << ans << endl;

}