#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int R, C;
    cin >> R >> C;
    int dist = max(abs(R-8), abs(C-8));
    cout << ((dist%2 == 0) ? "white" : "black") << endl;
}