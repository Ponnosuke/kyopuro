#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    vector<bool> flag(10, false);
    for(int i = 0; i < 9; i++){
        char ch;
        cin >> ch;
        flag.at(ch - '0') = true;
    }

    for(int i = 0; i <= 9; i++){
        if(!flag.at(i)){
            cout << i << endl;
        }
    }
}