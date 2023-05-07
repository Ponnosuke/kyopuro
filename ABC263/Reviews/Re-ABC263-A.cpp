#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    vector<int> vec(5);
    for(auto &x:vec) cin >> x;

    sort(vec.begin(), vec.end());

    // AABBB
    bool OK1 = (vec.at(0) == vec.at(1)) && (vec.at(2) == vec.at(4));
    // AAABB
    bool OK2 = (vec.at(0) == vec.at(2)) && (vec.at(3) == vec.at(4));

    cout << ((OK1 || OK2) ? "Yes" : "No") << "\n";
}