#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    vector<int> v(5);
    for(auto &x:v) cin >> x;

    map<int, int> m; // num cnt
    for(int i = 1; i <= 13; i++){
        m[i] = 0;
    }

    for(auto x:v){
        m[x]++;
    }

    bool OK1 = false, OK2 = false;
    for(int i = 1; i <= 13; i++){
        if(m.at(i) == 2) OK1 = true;
        if(m.at(i) == 3) OK2 = true;
    }

    cout << (OK1 && OK2 ? "Yes":"No") << endl;

    
}