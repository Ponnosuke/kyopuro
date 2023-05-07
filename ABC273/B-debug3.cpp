// AC
/*
考慮できていなかったケース

1. 操作を終えて answer が 0 になる場合
2. Line:33 にて、nums.at(i+1) が 10 になったときの対処


i64  ret = 0;
for(i64  i = keta; i >= 0; i--){
    ret += nums.at(i);
    if(i > 0) ret *= 10;
}

return ret;

でうまくいったのは、この操作が繰り上げに対応していたから 
(nums.at(i) == 10 のとき一つ上の桁に 1 が足される)

*/

#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    i64 X, K;
    cin >> X >> K;
    vector<i64> nums(17, 0);

    i64 tmp = X, keta = 0;
    for(int i = 0; i < 16; i++){
        nums.at(i) = (tmp % 10);
        tmp /= 10;
        if(tmp == 0){
            break;
        }
        else{
            keta++;
        }
    }

    for(int i = 0; i < K; i++){
        if(nums.at(i) >= 5){
            nums.at(i) = 0;
            nums.at(i+1)++;
        }
        else{
            nums.at(i) = 0;
        }
    }
  
    int tmpK = K;
    while(nums.at(tmpK) > 9){
        nums.at(tmpK + 1)++;
        nums.at(tmpK) = 0;
        tmpK++;
    }

    if(nums.at(keta + 1) >= 1){
        keta++;
    }


    if(nums.at(keta) == 0){
        cout << 0 << endl;
    }
    else{
        for(int i = keta; i >= 0; i--){
            cout << nums.at(i);
        }
    }

    cout << endl;
}