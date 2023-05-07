#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

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

    i64 ans = 0, num = 0;
    bool OK = true;

    for(int i = 0; i < N; i++){
        int tmpA = a.at(i) / allGCD, cnt = 0;
        while(tmpA % 2 == 0){
            cnt++;
            tmpA /= 2;
        }
        while(tmpA % 3 == 0){
            cnt++;
            tmpA /= 3;
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