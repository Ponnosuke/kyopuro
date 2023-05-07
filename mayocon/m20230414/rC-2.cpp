/*
    WA

    l > r のところとかもカウントしちゃってよくわからない事になってる
*/

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
    for(int i = 0; i < N; i++){
        rui.at(i+1) = rui.at(i) + A.at(i);
    }

    map<i64, i64> mp;  // num, cnt
    for(int i = 0; i <= N; i++){
        mp[rui.at(i)]++;
    }

    i64 ans = 0;
    for(auto [num, cnt1] : mp){
        // debugVL(num);

        // debugWL();
        if(mp.count(num - K)){

            // debugV(num);
            // debugVL(num + K);
            // debugV(mp[num]);
            // debugVL(mp[num + K]);

            i64 cnt2 = mp.at(num - K);
            ans += (cnt1 * cnt2);

            // debugV(cnt1);
            // debugV(cnt2);
            // debugVL(ans);
            // debugWL();
        }
    }

    cout << ans << endl;
}