/*
    AtCoder のオンラインコンパイル環境だと modinv() の方が速い。
    ローカル環境だと tempModInv() の方が速い。
*/


#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

// 非再帰のユークリッド互除法による逆元計算
// a の mod m における逆元を求める  
// a と m が互いに素でないといけないことに注意
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
// 引き算をしているので unsigned 系の型にするとおかしくなるので注意



// 再帰ユークリッド互除法による逆元計算のセット
i64 extGCD(i64 a, i64 b, i64 &x, i64 &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    i64 g = extGCD(b, a%b, y, x);
    y -= (a/b) * x;
    return g;
}
i64 tempModInv(i64 a, i64 m){
    i64 x, y;
    extGCD(a, m, x, y);
    return ((x % m) + m) % m;
}




const i64 MOD = 1000000007;
const i64 LOOP = 1000000;

int main() {
    int ti = clock();

    cout << fixed << setprecision(15);

    double first = 1.0 * (clock() - ti) / CLOCKS_PER_SEC;
    cout << first << '\n';

    for(int i = 1; i < LOOP; i++){
        // cout << i << " 's inv: " << modinv(i, MOD) << endl;
        modinv(i, MOD);
    }

    double second = 1.0 * (clock() - ti) / CLOCKS_PER_SEC;
    cout << second - first<< '\n';

    for(int i = 1; i < LOOP; i++){
        // cout << i << " 's inv: " << tempModInv(i, MOD) << endl;
        tempModInv(i, MOD);
    }

    double third = 1.0 * (clock() - ti) / CLOCKS_PER_SEC;
    cout << third - second << '\n';

    for(int i = 1; i < LOOP; i++){
        // cout << i << " 's inv: " << modinv(i, MOD) << endl;
        modinv(i, MOD);
    }

    double forth = 1.0 * (clock() - ti) / CLOCKS_PER_SEC;
    cout << forth - third << '\n';

    for(int i = 1; i < LOOP; i++){
        // cout << i << " 's inv: " << tempModInv(i, MOD) << endl;
        tempModInv(i, MOD);
    }

    double fifth = 1.0 * (clock() - ti) / CLOCKS_PER_SEC;
    cout << fifth - forth << '\n'; 
}