#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N;
    string S;
    cin >> N >> S;

    int ans = 0;
    for(int i = 0; i < N - 2 ; i++){
        if(S.substr(i,3) == "ABC") ans++;
    }

    cout << ans << endl;
}
