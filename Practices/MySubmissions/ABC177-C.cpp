// This is a WA.

#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;
using ll = long long;

const ll mod1 = 1e9 + 7;

int main() {
    ll N;
    cin >> N;

    vector<ll> A(N);
    for(auto &x : A)  cin >> x;

    ll sum = 0;
    for(auto x : A){
        sum += x;
    }

    ll ans = 0;
    for(ll i = 0; i < N; i++){
        sum -= A.at(i);
        sum %= mod1;
        ans += A.at(i) * sum;
        ans %= mod1;
    }

    cout << ans << endl;
}