#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    map<char, vector<int>> mp;
    mp['a'] = {1,2,3,4};
    mp['b'] = {3,4,5,6};
    mp['c'] = {4,5,6,7};

    mp['d'] = mp['a'];
    mp['d'].push_back(3390);

    for(int i = 0; i < 5; i++){
        cout << mp['d'].at(i) << endl;
    }
    // output
    /*
        1
        2
        3
        4
        3390
    */
}