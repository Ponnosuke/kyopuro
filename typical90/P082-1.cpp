/*
    WA
    なんか大きい数だとダメ
*/

#include <bits/stdc++.h>
using namespace std;

using ui64 = int64_t;
using uui64 = uint64_t;

const ui64 MOD = 1000000007;

ui64 modinv(ui64 a, ui64 m){
    ui64 b = m, s = 1, t = 0;
    while(b){
        ui64 q = a / b;
        a -= q * b;
        swap(a, b);
        s -= q * t;
        swap(s, t);
    }
    s = ((s % m) + m) % m;
    return s;
}

int main() {
    ui64 L, R;
    cin >> L >> R;

    ui64 left = 1, right = 10*left - 1, cnt = 1;
    ui64 sum = 0;
    ui64 twoInv = modinv(2, MOD);
    for(int i = 0; i < 19; i++){

        // debug
        // cerr << '\n' << "i = " << i << '\n';

        if(i > 0){
            left *= 10;
            right = 10ULL * left - 1;
            cnt++;

            // debug
            // cerr << "point40" << '\n';
            // cerr << "left, right, cnt = " << left << ", " << right << ", " << cnt << '\n';

        }

        if(right < L){

            // debug
            // cerr << "routeA" << '\n';

            continue;
        }
        else if(left <= L && L <= right && right < R){
            ui64  num1 = right + L, num2 = right - L + 1;
            num1 %= MOD;
            num2 %= MOD;
            sum += (((((num1 * num2) % MOD) * cnt) % MOD) * twoInv) % MOD;
            sum %= MOD;

            // debug
            // cerr << "routeB" << '\n';
            // cerr << "sum = " << sum << '\n';

        }
        else if(L < left && right < R){
            // ui64 num = right - left + 1;
            // sum += ((left + right) * num * cnt) / 2;
            ui64 num1 = left + right, num2 = right - left + 1;
            num1 %= MOD;
            num2 %= MOD;
            sum += (((((num1 * num2) % MOD) * cnt) % MOD) * twoInv) % MOD;
            sum %= MOD;

            // debug
            // cerr << "routeC" << '\n';
            // cerr << "sum = " << sum << '\n';

        }
        else if(left <= L && L <= right && left <= R && R <= right){
            // ui64 num = R - L + 1;
            // sum += ((L + R) * num * cnt) / 2;
            ui64 num1 = L + R, num2 = R - L + 1;
            num1 %= MOD;
            num2 %= MOD;
            sum += (((((num1 * num2) % MOD) * cnt) % MOD) * twoInv) % MOD;
            sum %= MOD;

            // debug
            // cerr << "routeD" << '\n';
            // cerr << "sum = " << sum << '\n';

        }
        else if(L < left && left <= R && R <= right){
            // ui64 num = R - left + 1;
            // sum += ((R + left) * num * cnt) / 2;
            ui64 num1 = R + left, num2 = R - left + 1;
            num1 %= MOD;
            num2 %= MOD;
            sum += (((((num1 * num2) % MOD) * cnt) % MOD) * twoInv) % MOD;
            sum %= MOD;

            // debug
            // cerr << "routeE" << '\n';
            // cerr << "sum = " << sum << '\n';

        }
        else{  // R < left

            // debug
            // cerr << "routeF" << '\n';

            break;
        }
    }

    cout << sum % MOD << '\n';

    return 0;
}