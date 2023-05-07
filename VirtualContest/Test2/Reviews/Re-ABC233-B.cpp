#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    i64 L, R;
    cin >> L >> R;
    string S;
    cin >> S;

    L--;
    R--;

    while(L < R){
        swap(S.at(L), S.at(R));
        L++;
        R--;
    }

    cout << S << endl;
}