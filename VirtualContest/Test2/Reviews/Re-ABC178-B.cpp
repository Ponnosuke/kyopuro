#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    i64 a,b,c,d;
    cin >> a >> b >> c >> d;
    cout << max(max(a*c, a*d), max(b*c, b*d)) << endl;
}