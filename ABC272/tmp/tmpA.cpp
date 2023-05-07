#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for(auto &x : A)  cin >> x;

    int sum = 0;
    for(auto x : A)  sum += x;

    cout << sum << endl;
}