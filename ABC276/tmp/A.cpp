#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    string S;
    cin >> S;
    int ans = -1;
    for(int i = 0; i < S.size(); i++){
        if(S.at(i) == 'a'){
            ans = i+1;
        }
    }
    cout << ans << endl;
}