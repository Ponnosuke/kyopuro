#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    i64 a, b;
    cin >> a >> b;

    i64 p = a * b;

    if(p % 2 == 0)  cout << "Even" << endl;
    else            cout << "Odd" << endl;
}