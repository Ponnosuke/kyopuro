#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

const i64 mod1 = 998244353;

int main() {
    i64 N;
    cin >> N;

    i64 ans = 0;
    for(i64 i = (N-mod1)/mod1 ; i * mod1 <= N; i++){
        if((0 <= N - mod1 * i) && (N - mod1 * i < mod1)){
            ans = N - mod1 * i;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}