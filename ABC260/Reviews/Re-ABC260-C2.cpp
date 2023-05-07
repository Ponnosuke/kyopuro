#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    i64 N, X, Y;
    cin >> N >> X >> Y;

    vector<i64> R(N+1), B(N+1);

    R.at(N) = 1;
    for(int i = N; i > 1; i--){
        R.at(i-1) += R.at(i);
        B.at(i) += X*R.at(i);
        // R.at(i) = 0;
        // 指定の処理通り無くしとくと安心かも
        R.at(i-1) += B.at(i);
        B.at(i-1) += B.at(i)*Y;
    }

    cout << B.at(1) << endl;
}