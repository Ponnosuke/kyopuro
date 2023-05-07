#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    i64 N;
    cin >> N;
    string S;
    cin >> S;

    i64 posO = 0, posX = 0, ans = 0;
    for(i64 i = 0; i < N; i++){
        i64 now = i + 1;
        if(S.at(i) == 'o'){
            posO = now;
        }
        else{
            posX = now;
        }

        ans += min(posO, posX);
    }

    cout << ans << endl;
}