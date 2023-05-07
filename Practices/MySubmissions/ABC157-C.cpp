// This is a WA

#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> s(M), c(M);
    for(int i = 0; i < M; i++){
        cin >> s.at(i) >> c.at(i);
    }

    map<int, int> mp;
    for(int i = 0; i < M; i++){
        if(!mp.count(s.at(i))){
            mp[s.at(i)] = c.at(i);
        }
        else{
            if(mp.at(s.at(i)) != c.at(i)){
                cout << -1 << endl;
                return 0;
            }
        }
    }

    int ans = 1;
    if(mp.count(1)){
        if((N == 3) && (mp.at(1) == 0)){
            cout << -1 << endl;
            return 0;
        }
        ans += mp.at(1) - 1;
    }
    ans *= 10;
    if(mp.count(2)){
        ans += mp.at(2);
    }
    ans *= 10;
    if(mp.count(3)){
        ans += mp.at(3);
    }

    cout << ans << endl;
}