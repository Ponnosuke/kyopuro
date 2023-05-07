#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N, K;
    cin >> N >> K;

    int now = 1;
    for(int i = 0; i < N; i++){
        now = min(now*2, now + K);
    }

    cout << now << endl;
}