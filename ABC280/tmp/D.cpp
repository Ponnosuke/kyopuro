#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    i64 K;
    cin >> K;


    i64 tmpK = K, maxFac = 2;
    map<i64, i64> mp;
    for(i64 a = 2; a*a <= tmpK; a++){
        if(tmpK % a != 0){
            continue;
        }
        i64 x = 0;
        while(tmpK % a == 0){
            x++;
            tmpK /= a;
        }

        maxFac = a;
        mp[a] = x;
    }

    i64 secondFac = maxFac;
    if(tmpK != 1){
        maxFac = tmpK;
    }

    if(maxFac == K){
        cout << K << '\n';
        return 0;
    }

    i64 ans = -1, tmp1 = 1;
    for(int i = 2; i*i <= K; i++){
        tmp1 *= i;
        tmp1 %= K;
        if(tmp1 == 0){
            ans = K;
            break;
        }
    }

    cout << ans << '\n';

    return 0;
}