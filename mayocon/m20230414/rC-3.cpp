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
    i64 N, K;
    cin >> N >> K;
    vector<i64> A(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }

    vector<i64> rui(N+1, 0);
    map<i64, i64> mp;  // num, cnt
    i64 ans = 0;
    mp[rui.at(0)]++;
    for(int i = 0; i < N; i++){
        rui.at(i+1) = rui.at(i) + A.at(i);
        
        if(mp.count(rui.at(i+1) - K)){
            ans += mp.at(rui.at(i+1) - K);
        }
        mp[rui.at(i+1)]++;
    }

    cout << ans << endl;
}