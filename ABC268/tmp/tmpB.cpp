#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    string S, T;
    cin >> S >> T;

    if(S.size() > T.size()){
        cout << "No" << endl;
        return 0;
    }

    bool OK = true;
    for(int i = 0; i < S.size(); i++){
        if(S.at(i) != T.at(i)){
            OK = false;
            break;
        }
    }

    cout << (OK ? "Yes" : "No") << endl;

    return 0;
}