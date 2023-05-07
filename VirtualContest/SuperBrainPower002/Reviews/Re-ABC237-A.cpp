#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    i64 N;
    cin >> N;

    i64 num = (i64)1 << 31;
    // i64 num = (i64)(1 << 31);
    // これだと i64 num = (i64)((int)1 << 31)  と解釈されてしまう。

    bool OK = -num <= N && N < num;

    cout << (OK ? "Yes" : "No") << endl;
}