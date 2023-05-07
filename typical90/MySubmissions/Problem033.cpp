#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int H, W;
    cin >> H >> W;

    int ans = 0;
    if(H == 1 || W == 1){
        ans = H * W;
    }
    else{
        if(H % 2 != 0)  H++;
        if(W % 2 != 0)  W++;
        ans = (H / 2) * (W / 2);
    }

    cout << ans << endl;
}