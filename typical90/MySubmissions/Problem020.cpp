#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    i64 a, b, c;
    cin >> a >> b >> c;
    i64 r = 1;
    for(int i = 0; i < b; i++){
        r *= c;
    }

    cout << ((a < r) ? "Yes" : "No") << '\n';
}