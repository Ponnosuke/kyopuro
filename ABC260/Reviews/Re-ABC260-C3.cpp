#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    i64 N, X, Y;
    cin >> N >> X >> Y;

    vector<i64> R(N+1), B(N+1);
    R.at(1) = 0;
    B.at(1) = 1;
    for(int i = 2; i <= N; i++){
        B.at(i) = R.at(i-1) + Y*B.at(i-1);
        R.at(i) = R.at(i-1) + X*B.at(i);
    }

    cout << R.at(N) << endl;
}