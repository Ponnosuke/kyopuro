#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

i64 myGCD(i64 a, i64 b){
    if(b == 0){
        return a;
    }
    else{
        return myGCD(b, a % b);
    }
}
/*
1. 大きい方を小さい方で割る
2. 大きい方を 1で出た余りに置き換える

a < b のときも a % b = a なので再帰呼び出しのところで入れ替わる
また、 a >= b を満たしたら b > a%b となることより、
再帰的に呼び出される関数たちは常に a > b を満たす
*/



i64 myGCD2(i64 a, i64 b){
    return (b ? myGCD2(b, a % b) : a);
}
/*
簡易化
b == 0 だと false, それ以外だと(であってるかな, ようは値があると) trueを返すことを利用
*/




// return: gcd(a, b)
// ax + by = gcd(a,b) を満たす (x, y) が格納される
// &x, &y  参照渡し
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





int main() {
    int a = 3389, b = 3391;
    cout << myGCD(a, b) << "\n";

    i64 x, y;
    i64 g = extGCD(a, b, x, y);
    cout << g << '\n';
    cout << x << ", " << y << "\n";

    return 0;
}