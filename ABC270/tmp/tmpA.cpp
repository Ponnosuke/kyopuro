#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int A, B;
    cin >> A >> B;
    bitset<3> bitA(A), bitB(B);
    bitset<3> bitC = (bitA | bitB);
    int ans = 0;
    if(bitC.test(0)) ans += 1;
    if(bitC.test(1)) ans += 2;
    if(bitC.test(2)) ans += 4;

    cout << ans << endl;
}