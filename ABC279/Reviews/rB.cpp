#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    string S, T;
    cin >> S >> T;

    int sizeS = S.size(), sizeT = T.size();
    bool OK = false;
    for(int i = 0; i <= sizeS - sizeT; i++){
        if(S.substr(i, sizeT) == T){
            OK = true;
            break;
        }
    }

    cout << (OK ? "Yes" : "No") << '\n';
}