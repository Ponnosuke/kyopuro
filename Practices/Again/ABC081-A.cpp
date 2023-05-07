#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int cnt = 0;
    for(int i = 0; i < 3; i++){
        char s;
        cin >> s;
        int num = s - '0';

        // debug
        // cout << "i = " << i << ", num = " << num << endl;

        if(num == 1)  cnt++;
    }

    cout << cnt << endl;
}