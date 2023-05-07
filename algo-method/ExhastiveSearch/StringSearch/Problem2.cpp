#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    string S;
    cin >> S;

    string revS = S;

    reverse(revS.begin(), revS.end());  // S自体を並び変える。参照渡し？

    bool areSame = true;
    for(int i = 0; i < S.size(); i++){
        if(S.at(i) != revS.at(i))  areSame = false;
    }

    cout << (areSame ? "Yes" : "No") << endl;
}