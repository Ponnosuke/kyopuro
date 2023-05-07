/*
WA の提出で考慮できていなかったケース

1. 操作を終えて answer が 0 になる場合
2. Line:33 にて、nums.at(i+1) が 10 になったときの対処

WAコードのデバッグの時の出力で

i64  ret = 0;
for(i64  i = keta; i >= 0; i--){
    ret += nums.at(i);
    if(i > 0) ret *= 10;
}

return ret;

でうまくいったのは、この操作が繰り上げに対応していたから 
(nums.at(i) == 10 のとき一つ上の桁に 1 が足される)
また、これなら 0 の時も上手く対処できる

*/

#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    i64 X, K;
    cin >> X >> K;

    for(int i = 0; i < K; i++){
        i64 tmp = 1;
        for(int j = 0; j < i; j++){
            tmp *= 10;
        }

        X += 5*tmp;
        X = (X / (tmp * 10)) * (tmp * 10);
    }

    cout << X << endl;
}