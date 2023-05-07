#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    map<int, int> mp;
    mp[1] = 5;
    mp[6] = 3;
    mp[3] = 2;

    for(auto ele : mp){
        cout << "key = " << ele.first << ":" << " value = " << ele.second << endl;
    }

    /*
    OUTPUT:

    key = 1: value = 5
    key = 3: value = 2
    key = 6: value = 3
    */

    return 0;
}