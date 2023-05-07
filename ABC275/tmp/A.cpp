#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N;
    cin >> N;

    int ans = 0, now = -1;
    for(int i = 1; i <= N; i++){
        i64 h;
        cin >> h;
        if(h > now){
            now = h;
            ans = i;
        }
    }

    cout << ans << endl;
}