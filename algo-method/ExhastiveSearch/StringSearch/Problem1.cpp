#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    string S;
    char c;
    cin >> S >> c;

    bool exist = false;
    for(auto ch : S){
        if(ch == c)  exist = true;
    }

    cout << (exist ? "Yes" : "No") << endl;
}