#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int L, R;
    cin >> L >> R;
    string str = "atcoder";

    cout << str.substr(L - 1, R - L + 1) << endl;
}