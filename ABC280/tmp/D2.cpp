#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    i64 K;
    cin >> K;

    i64 tmpK = K, maxFac = 2;
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
    }

    i64 secondFac = maxFac;
    if(tmpK != 1){
        maxFac = tmpK;
    }

    if(maxFac == K){
        cout << K << '\n';
        return 0;
    }
    else{
        i64 tmp = 1, ans = K;
        for(int i = 2; i <= 100000000; i++){
            tmp *= (i % K);
            tmp %= K;
            if(tmp == 0){
                ans = i;
                break;
            }
        }

        cout << ans << '\n';
    }
}