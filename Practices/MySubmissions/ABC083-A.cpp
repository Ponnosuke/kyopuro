#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    int L = A + B, R = C + D;

    if(L > R){
        cout << "Left" << endl;
    }
    else if(L < R){
        cout << "Right" << endl;
    }
    else{
        cout << "Balanced" << endl;
    }
}