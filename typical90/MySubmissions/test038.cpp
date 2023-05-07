#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

const i64 MAX = (i64)1e18;

int main() {
    i64 A;
    cin >> A;

    map<i64, i64> mp;
    for(i64 i = 2; i * i <= A; i++){
        if(A % i != 0){
            continue;
        }

        i64 cnt = 0;
        while(A % i == 0){
            cerr << "i = " << i << '\n';
            cerr << "A = " << A << '\n';
            cerr << "A % i = " << A % i << '\n';
            cerr << "A / i = " << A / i << '\n' << '\n';
            A /= i;
            cnt++;
        }

        mp[i] = cnt;
    }



    for(auto [p, cnt] : mp){
        cerr << "p cnt = " << p << " " << cnt << '\n';
    }
}