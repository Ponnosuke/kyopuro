#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N;
    cin >> N;

    int ans = 0;
    for(int i = 1; i <= N; i += 2){
        int dCnt = 0;
        for(int j = 1; j <= i ; j++){
            if(i % j == 0) dCnt++;
        }
        if(dCnt == 8) ans++;
    }

    cout << ans << endl;
}