#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    string S;
    cin >> S;

    int cnt = 0;
    for(int i = 0; i < S.size() - 1 ; i++){
        if(S.at(i) == S.at(i + 1))  cnt++;
    }

    cout << cnt << endl;
}