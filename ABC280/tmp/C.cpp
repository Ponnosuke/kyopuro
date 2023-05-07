#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    string S, T;
    cin >> S >> T;

    int ans = (int)T.size();
    for(int i = 0; i < (int)S.size(); i++){
        if(S.at(i) != T.at(i)){
            ans = i+1;
            break;
        }
    }

    cout << ans << endl;
}