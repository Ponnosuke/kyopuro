#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    i64 A, B, K;
    cin >> A >> B >> K;

    int cnt = 0;
    while(A < B){
        cnt++;
        A *= K;
    }

    cout << cnt << endl;
}