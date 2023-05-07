#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    i64 N, K;
    cin >> N >> K;
    vector<i64> A(N, 0), B(N, 0);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }
    for(int i = 0; i < N; i++){
        cin >> B.at(i);
    }

    for(int i = 0; i < N; i++){
        K -= abs(A.at(i) - B.at(i));
    }

    bool OK = ((K >= 0) && (K % 2 == 0));
    cout << (OK ? "Yes" : "No") << "\n";

    return 0;
}