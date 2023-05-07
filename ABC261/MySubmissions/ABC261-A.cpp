#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int L1, R1, L2, R2;
    cin >> L1 >> R1 >> L2 >> R2;

    if(L1 == L2 && R1 == R2){
        cout << R1 - L1 << endl;
    }
    else if(R1 <= L2 || R2 <= L1){
        cout << 0 << endl;
    }
    else if(L2 <= L1 && R1 <= R2){
        cout << R1 - L1 << endl;
    }
    else if(L1 <= L2 && R2 <= R1){
        cout << R2 - L2 << endl;
    }
    else if(R1 > L2 && L1 < L2 && R1 < R2){
        cout << R1 - L2 << endl;
    }
    else if(R2 > L1 && L2 < L1 && R2 < R1){
        cout << R2 - L1 << endl;
    }
}