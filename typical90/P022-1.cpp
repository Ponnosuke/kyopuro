#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

i64 myGCD(i64 a, i64 b){
    if(b == 0){
        return a;
    }
    else{
        return myGCD(b, a % b);
    }
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