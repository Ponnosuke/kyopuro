#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int L1, R1, L2, R2;
    cin >> L1 >> R1 >> L2 >> R2;

    cout << max(0, min(R1, R2) - max(L1, L2)) << endl;
}