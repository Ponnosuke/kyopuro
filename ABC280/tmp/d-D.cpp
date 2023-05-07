#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

// 愚直解
i64 solve1(i64 K){
    i64 tmp = 1, ret = K;
    for(int a = 2; a <= K; a++){
        tmp *= a;
        tmp %= K;
        if(tmp % K == 0){
            ret = a;
            break;
        }
    }

    return ret;
}

i64 solve2(i64 K){
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

    if(tmpK != 1){
        maxFac = tmpK;
    }

    i64 ans = maxFac;

    for(auto [p, q] : mp){
        i64 cnt = (ans/p);
        if(q > cnt){
            ans = p + p*(q-cnt);
        }
    }

    return ans;
}

i64 solve3(i64 K){
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
        return K;
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

    return ans;
}

int main() {

    cout << "start!" << '\n';

    i64 maxAns = -1;
    for(int i = 2; i < 100000; i++){
        i64 s1 = solve1(i), s2 = solve3(i);
        if(s1 != s2){
            cout << "Wrong Answer!" << '\n';
            cout << "i = " << i << '\n';
            cout << "solve1(" << i << ") = " << s1 << '\n';
            cout << "solve3(" << i << ") = " << s2 << '\n';
            // break;
        }
        if(s1 != i){
            maxAns = max(maxAns, s1);
        }
    }

    cout << "maxAns = " << maxAns << '\n';
    cout << "finish!" << '\n';
}