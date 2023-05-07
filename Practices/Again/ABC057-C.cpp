#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

const i64 INF = 1LL << 62;

int main() {
    i64 N;
    cin >> N;

    i64 ans = INF;
    for(i64 i = 1; i * i <= N; i++){
        if(N % i == 0){
            i64 A = i, B = N/i;

            ans = min((i64)max(to_string(A).size(), to_string(B).size()), ans);
        }
    }

    cout << ans << endl;
}