#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N;
    cin >> N;
    string S, T;
    cin >> S >> T;

    int cnt = 0;
    for(int i = 0; i < S.size() ; i++){
        if(S.at(i) != T.at(i))  cnt++;
    }

    cout << cnt << endl;
}