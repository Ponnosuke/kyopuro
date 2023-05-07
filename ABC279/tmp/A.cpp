#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    string S;
    cin >> S;
    map<char, int> mp;

    for(auto ch : S){
        mp[ch]++;
    }
    int ans = 0;
    ans += mp['v'];
    ans += mp['w'] * 2;

    cout << ans << endl;
}