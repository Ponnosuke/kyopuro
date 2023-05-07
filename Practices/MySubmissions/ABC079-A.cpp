#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    string N;
    cin >> N;

    bool isGood1 = N.at(0) == N.at(1) && N.at(1) == N.at(2);
    bool isGood2 = N.at(1) == N.at(2) && N.at(2) == N.at(3);

    cout << (isGood1 || isGood2 ? "Yes":"No") << "\n";
}