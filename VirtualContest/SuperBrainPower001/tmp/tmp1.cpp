#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int A, B;
    cin >> A >> B;

    A = A + B;

    if(15<=A && 8 <= B){
        cout << 1 << endl;
    }
    else if(10<=A && 3<=B){
        cout << 2 << endl;
    }
    else if(3<=A){
        cout << 3 << endl;
    }
    else{
        cout << 4 << endl;
    }
}