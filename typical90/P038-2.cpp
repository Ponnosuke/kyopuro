#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

const i64 POW18 = 1000000000000000000LL;

i64 myGCD(i64 a, i64 b){
    if(b == 0){
        return a;
    }
    else{
        return myGCD(b, a % b);
    }
}

int main() {
    i64 A, B;
    cin >> A >> B;

    i64 r = B / myGCD(A, B);
    if(A > POW18 / r){
        cout << "Large" << endl;
    }
    else{
        cout << A*r << endl;
    }
}