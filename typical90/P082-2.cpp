#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;
using mint = atcoder::modint1000000007;

int main() {
    i64 L, R;
    cin >> L >> R;

    i64 left = 1, right = 10*left - 1, cnt = 1;
    mint sum = 0, mleft = left, mright = right, mcnt = cnt, mL = L, mR = R;
    for(int i = 0; i < 18; i++){
        if(i > 0){
            left *= 10;
            right = 10*left - 1;
            cnt++;

            mleft = left;
            mright = right;
            mcnt = cnt;
        }


        if(right < L){
            continue;
        }
        else if(left <= L && L <= right && right < R){
            sum += ((mright + mL) * (mright - mL + 1) * mcnt ) / 2;
        }
        else if(L < left && right < R){
            sum += ((mleft + mright) * (mright - mleft + 1) * mcnt) / 2;
        }
        else if(left <= L && L <= right && left <= R && R <= right){
            sum += ((mL + mR) * (mR - mL + 1) * mcnt) / 2;
        }
        else if(L < left && left <= R && R <= right){
            sum += ((mR + mleft) * (mR - mleft + 1) * mcnt) / 2;
        }
        else{  // R < left
            break;
        }
    }
    if(right < R){
        sum += 19 * (mright + 1);
    }

    cout << sum.val() << '\n';

    return 0;
}