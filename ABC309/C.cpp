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
    vector<i64> a(N), b(N);
    // vector<i64> table;
    map<i64, i64> mp;
    i64 now_cnt = 0;
    for(i64 i = 0; i < N; i++){
        cin >> a.at(i) >> b.at(i);

        mp[a.at(i)] += b.at(i);
        now_cnt += b.at(i);
        // table.push_back(a.at(i));
    }

    i64 now_day = 1;
    i64 ans = -1;

    for(auto [p, q] : mp){

        debugV(p);
        debugVL(q);

        if(now_cnt <= K){
            ans = now_day;
            break;
        }

        now_day = p+1;
        now_cnt -= q;

    }

    if(ans == -1){
        cout << now_day << endl;
    }
    else{
        cout << ans << endl;
    }
}