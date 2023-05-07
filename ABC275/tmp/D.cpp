#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

map<i64, i64> mp;

i64 f(i64 n){
    if(n == 0){
        return 1;
    }

    if(mp.count(n)){
        return mp.at(n);
    }

    i64 ret = f(n/2) + f(n/3);

    mp[n] = ret;

    return ret;
}

int main() {
    i64 N;
    cin >> N;
    cout << f(N) << '\n';
}