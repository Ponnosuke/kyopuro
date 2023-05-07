#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

const i64 MAX = (i64)1e18;

int main() {
    i64 A, B;
    cin >> A >> B;

    map<i64, i64> mp;
    for(i64 i = 2; i * i <= A; i++){
        if(A % i != 0){
            continue;
        }

        i64 cnt = 0;
        while(A % i == 0){
            A /= i;
            cnt++;
        }

        mp[i] = cnt;
    }
    if(A != 1){
        mp[A] = 1;
    }

    for(i64 i = 2; i * i <= B; i++){
        if(B % i != 0){
            continue;
        }

        i64 cnt = 0;
        while(B % i == 0){
            B /= i;
            cnt++;
        }

        mp[i] = max(mp[i], cnt);
    }
    if(B != 1){
        mp[B] = max(mp[B], (i64)1);
    }

    i64 ans = 1;
    bool OK = true;
    for(auto [p, cnt] : mp){
        for(i64 i = 0; i < cnt; i++){
            if(ans > (MAX / p)){
                OK = false;
                break;
            }
            else{
                ans *= p;
            }
        }
    }

    if(OK){
        cout << ans << '\n';
    }
    else{
        cout << "Large" << '\n';
    }
}