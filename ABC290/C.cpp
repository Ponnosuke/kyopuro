#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << X << " "
    #define debugV(X) std::cerr << #X << " = " << X << ", "
    #define debugVL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugWL(Z) std::cerr << #Z << '\n'
    #define debugP() std::cerr << "Line:" << __LINE__ << '\n'
#else
    #define debug(X)
    #define debugV(X)
    #define debugVL(Y)
    #define debugWL(Z)
    #define debugP()
#endif

int main() {
    int N, K;
    cin >> N >> K;
    map<i64, i64> mp;
    bool zeroExisted = false;
    for(int i = 0; i < N; i++){
        i64 iA;
        cin >> iA;
        if(iA == 0){
            zeroExisted = true;
        }

        mp[iA]++;
    }

    if(!zeroExisted){
        cout << 0 << '\n';

        return 0;
    }

    i64 ans = 0;
    for(auto [num, cnt] : mp){

        debugV(num);
        debugV(cnt);
        debugVL(K);

        if(num == ans){
            ans++;
            K--;
            if(K <= 0){
                break;
            }
        }
        else{
            break;
        }
    }

    cout << ans << '\n';
}