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
    i64 N, M;
    cin >> N >> M;
    vector<i64> p(N, -1);
    for(int i = 1; i < N; i++){
        cin >> p[i];
        p[i]--;
    }
    vector<i64> x(M), y(M);
    for(int i = 0; i < M; i++){
        cin >> x[i] >> y[i];
        x[i]--;
    }

    vector<vector<i64>> to_G(N);
    vector<i64> hp(N, 0);
    priority_queue<pair<i64, i64>> pq;
    for(int i = 1; i < N; i++){
        to_G[p[i]].push_back(i);
    }
    for(int i = 0; i < M; i++){
        hp[x[i]] = max(hp[x[i]], y[i] + 1);
    }
    for(int i = 0; i < N; i++){
        if(hp[i] > 0){
            pq.emplace(hp[i], i);
        }
    }

    while(!pq.empty()){
        auto [now_hp, person] = pq.top();
        pq.pop();

        if(hp[person] != now_hp){
            continue;
        }
        if(now_hp == 1){
            continue;
        }

        for(i64 np : to_G[person]){

            if(hp[np] >= now_hp){
                continue;
            }

            hp[np] = now_hp - 1;
            pq.emplace(now_hp-1, np);
        }
    }

    i64 ans = 0;
    for(int i = 0; i < N; i++){
        if(hp[i] > 0){
            ans++;
        }
    }

    cout << ans << endl;
}