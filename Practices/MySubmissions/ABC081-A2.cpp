#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    string s;
    cin >> s;

    int ans = 0;
    for(auto c:s){
        if(c == '1')  ans++;
    }

    cout << ans << endl;
}