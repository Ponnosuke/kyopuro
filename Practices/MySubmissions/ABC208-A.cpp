#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int A, B;
    cin >> A >> B;

    bool OK1 = (6 * A >= B);
    bool OK2 = (1 * A <= B);
    bool OK = (OK1 && OK2);
    
    cout << (OK ? "Yes" : "No") << endl;
}