#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    string S;
    cin >> S;

    set<char> charSet;

    int ans = 0;
    for(auto c:S){
        if(!(charSet.count(c))){
            charSet.insert(c);
            ans++;
        }
    }

    cout << ans << endl;
}