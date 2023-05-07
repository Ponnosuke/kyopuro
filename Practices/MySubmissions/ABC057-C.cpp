#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

const i64 INF = (i64)1 << 60;

i64 cntDigits(i64 n){
    string digits = to_string(n);
    return (i64)digits.size();
}

int main() {
    i64 N;
    cin >> N;

    i64 ans = INF;
    for(i64 a = 1 ; a*a <= N; a++){
        if(N % a != 0) continue;

        i64 b = N / a;
        i64 tmp = max(cntDigits(a), cntDigits(b));

        ans = min(ans, tmp);
    }

    cout << ans << endl;
}