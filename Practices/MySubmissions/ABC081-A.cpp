#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    vector<int > s(3);
    for(int i = 0 ; i < 3 ; i++){
        char c;
        cin >> c;
        s.at(i) = c - '0';
    }

    int ans = 0;
    for(auto x:s){
        if(x == 1)  ans++;
    }

    cout << ans << endl;
}