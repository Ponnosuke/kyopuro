#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

i64 myGCD(i64 a, i64 b){
    return (b ? myGCD(b, a % b) : a);
}

int main() {
    i64 A, B, C;
    cin >> A >> B >> C;

    i64 u = myGCD(A, myGCD(B, C));
    i64 ans = 0;
    ans += A / u - 1;
    ans += B / u - 1;
    ans += C / u - 1;

    cout << ans << "\n";

    return 0;    
}