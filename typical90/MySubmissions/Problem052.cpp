#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

const i64 MOD = 1000000007LL;

int main() {
    int N;
    cin >> N;
    vector<vector<i64>> A(N, vector<i64>(6, 0));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 6; j++){
            cin >> A.at(i).at(j);
        }
    }

    i64 ans = 1;
    for(int i = 0; i < N; i++){
        i64 tmp = 0;
        for(int j = 0; j < 6; j++){
            tmp += A.at(i).at(j);
        }
        ans *= tmp;
        ans %= MOD;
    }

    cout << ans << endl;
}