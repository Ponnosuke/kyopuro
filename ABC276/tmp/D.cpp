/*
    WA
*/

#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;


/*
  This function is from
    https://algo-logic.info/calc-pow/
*/
i64 myPOW(i64 x, i64 n){
    i64 ret = 1;
    while(n > 0){
        if(n & 1) ret *= x;
        x *= x;
        n >>= 1;
    }
    return ret;
}


int main() {
    int N;
    cin >> N;
    vector<i64> a(N);
    for(int i = 0; i < N; i++){
        cin >> a.at(i);
    }

    i64 allGCD = a.at(0);
    for(int i = 1; i < N; i++){
        allGCD = gcd(allGCD, a.at(i));
    }

    // debug
    // cerr << "allGCD = " << allGCD << '\n';

    i64 ans = 0, num = 0;
    bool OK = true;

    for(int i = 0; i < N; i++){
        int tmpA = a.at(i) / allGCD, cnt = 0;
        if(tmpA % 2 == 0){
            int tmp1 = (tmpA / 2);
            cnt += tmp1;
            for(int i = 0; i < tmp1; i++){
                tmpA /= 2;
            }
        } 
        if(tmpA % 3 == 0){
            int tmp1 = (tmpA / 3);
            cnt += tmp1;
            for(int i = 0; i < tmp1; i++){
                tmpA /= 3;
            }
        }

        if(i == 0){
            ans += cnt;
            num = tmpA;
        }
        else{
            if(num != tmpA){
                OK = false;
                break;
            }
            else{
                ans += cnt;
            }
        }
    }

    if(OK){
        cout << ans << '\n';
    }
    else{
        cout << -1 << '\n';
    }
}