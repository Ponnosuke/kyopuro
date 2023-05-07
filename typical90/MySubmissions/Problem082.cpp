#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

const i64 MOD = 1000000007;

i64 modinv(i64 a, i64 m){
    i64 b = m, s = 1, t = 0;
    while(b){
        i64 q = a / b;
        a -= q * b;
        swap(a, b);
        s -= q * t;
        swap(s, t);
    }
    s = ((s % m) + m) % m;
    return s;
}

int main() {
    i64 L, R;
    cin >> L >> R;

    i64 left = 1, right = 10*left - 1, cnt = 1;
    i64 sum = 0;
    i64 twoInv = modinv(2, MOD);
    for(int i = 0; i < 18; i++){
        if(i > 0){
            left *= 10;
            right = 10*left - 1;
            cnt++;
        }

        if(right < L){
            continue;
        }
        else if(left <= L && L <= right && right < R){
            i64  num1 = right + L, num2 = right - L + 1;
            num1 %= MOD;
            num2 %= MOD;
            sum += (((((num1 * num2) % MOD) * cnt) % MOD) * twoInv) % MOD;
            sum %= MOD;
        }
        else if(L < left && right < R){
            i64 num1 = left + right, num2 = right - left + 1;
            num1 %= MOD;
            num2 %= MOD;
            sum += (((((num1 * num2) % MOD) * cnt) % MOD) * twoInv) % MOD;
            sum %= MOD;
        }
        else if(left <= L && L <= right && left <= R && R <= right){
            i64 num1 = L + R, num2 = R - L + 1;
            num1 %= MOD;
            num2 %= MOD;
            sum += (((((num1 * num2) % MOD) * cnt) % MOD) * twoInv) % MOD;
            sum %= MOD;
        }
        else if(L < left && left <= R && R <= right){
            i64 num1 = R + left, num2 = R - left + 1;
            num1 %= MOD;
            num2 %= MOD;
            sum += (((((num1 * num2) % MOD) * cnt) % MOD) * twoInv) % MOD;
            sum %= MOD;
        }
        else{  // R < left
            break;
        }
    }
    if(right < R){
        sum += (19 * ((right + 1) % MOD)) % MOD;
        sum %= MOD;
    }

    cout << sum % MOD << '\n';

    return 0;
}