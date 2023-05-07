#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int L, R;
    cin >> L >> R;
    string S;
    cin >> S;

    string mid = S.substr(L-1, R-L+1);
    reverse(mid.begin(), mid.end());

    cout << S.substr(0, L-1) + mid + S.substr(R) << endl;
}