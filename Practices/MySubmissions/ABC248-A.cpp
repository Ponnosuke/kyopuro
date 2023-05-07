#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    set<int> S;
    for(int i = 0; i < 9; i++){
        char ch;
        cin >> ch;
        S.insert(ch - '0');
    }

    for(int i = 0; i <= 9; i++){
        if(!S.count(i)){
            cout << i << endl;
        }
    }
}