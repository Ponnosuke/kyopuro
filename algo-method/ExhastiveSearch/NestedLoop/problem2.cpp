#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N, K;
    cin >> N >> K;

    int ans = 0;
    for(int i = 1; i <= N; i++){
        int divCnt = 0;
        for(int j = 1; j <= i; j++){
            if(i % j == 0)  divCnt++;
        }

        if(divCnt == K) ans++;
    }

    cout << ans << endl;
}