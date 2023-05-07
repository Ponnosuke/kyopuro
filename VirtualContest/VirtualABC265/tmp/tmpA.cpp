#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

const i64 INF = 1e15;

int main() {
    int X, Y, N;
    cin >> X >> Y >> N;

    i64 ans = INF;
    for(int j = 0; 3*j <= N; j++){
        i64 tmp = X*(N - 3*j) + Y*j;
        ans = min(ans, tmp);
    }

    cout << ans << endl;
}