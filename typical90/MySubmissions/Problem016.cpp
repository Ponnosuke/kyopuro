#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

const i64 INF = (i64)1e17;

int main() {
    i64 N, A, B, C;
    cin >> N >> A >> B >> C;

    i64 ans = INF;
    for(int i = 0; i <= 9999; i++){
        for(int j = 0; i + j <= 9999; j++){
            i64 rem = N - (A*i + B*j);
            if(rem < 0){
                continue;
            }
            
            if(rem % C == 0){
                i64 tmp = i + j + rem/C;
                ans = min(ans, tmp);
            }
        }
    }

    cout << ans << endl;
}