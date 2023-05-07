#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    i64 N;
    cin >> N;

    i64 cnt = 0;
    for(i64 i = 2; i * i <= N; i++){
        // if(N % i != 0){
        //     continue;
        // }

        while(N % i == 0){
            cnt++;
            N /= i;
        }
    }
    if(N > 1){
        cnt++;
    }

    i64 ans = 0;
    while(cnt > (1 << ans)){
        ans++;
    }

    cout << ans << '\n';
}