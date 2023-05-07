#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    string S;
    cin >> S;

    bool isKaibun = true;
    for(int i = 0; i < S.size() ; i++){
        if(S.at(i) != S.at(S.size() - 1 - i))  isKaibun = false;
    }

    cout << (isKaibun ? "Yes" : "No") << endl;
}