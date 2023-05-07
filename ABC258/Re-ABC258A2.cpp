#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int K;
    cin >> K;

    int h, m;
    h = 21 + K/60;
    m = K % 60;

    cout << h << ":";
    if(m < 10) cout << 0;
    cout << m << "\n";
}