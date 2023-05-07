#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    string S;
    cin >> S;

    map<char, int> mp;  // map<char, int> の場合は 0 で初期化される
    for(auto c:S){
        mp[c]++;
    }

    for(auto [c,i]:mp){
        if(i == 1){
            cout << c << endl;
            return 0;
        }
    }

    cout << -1 << endl;

}