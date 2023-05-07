#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int Y;
    cin >> Y;

    for(int i = 0; i < 1300; i++){
        if(Y % 4 == 2)  break;
    
        Y++;
    }

    cout << Y << endl;
}