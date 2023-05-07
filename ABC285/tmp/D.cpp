#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << X << " "
    #define debugV(X) std::cerr << #X << " = " << X << ", "
    #define debugVL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugW(Z) std::cerr << #Z << '\n'
#else
    #define debug(X)
    #define debugV(X)
    #define debugVL(Y)
    #define debugW(Z)
#endif

int main() {
    i64 N;
    cin >> N;
    vector<string> S(N), T(N);
    map<string, string> mp;
    map<string, int> per;
    for(int i = 0; i < N; i++){
        cin >> S.at(i) >> T.at(i);
        mp[S.at(i)] = T.at(i);
        per[S.at(i)] = i;
    }

    bool OK = true;
    vector<bool> seen(N, false);
    i64 cnt = 0;
    for(int i = 0; i < N; i++){
        if(seen.at(i)){
            continue;
        }

        seen.at(i) = true;
        cnt++;
        int index = i;
        string now = mp[S.at(index)];
        while(cnt < N){
            if(per.count(now)){
                now = mp[S.at(index)];
                int index = per.at(now);
                if(seen.at(index)){
                    OK = false;
                    break;
                }
                seen.at(index) = true;
                cnt++;
            }
            else{
                break;
            }
        }

        if(!OK){
            break;
        }
    }

    if(OK){
        cout << "Yes" << '\n';
    }
    else{
        cout << "No" << '\n';
    }
}