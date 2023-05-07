#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int A, B;
    cin >> A >> B;
    int ans = (((10000 * B) / A) + 5) / 10;

    cout << ans / 1000 << "." << (ans / 100) % 10 << (ans / 10) % 10 << ans % 10 << endl;
}