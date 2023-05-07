#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << #X << " = " << X << ", "
    #define debugL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugP(Z) std::cerr << #Z << '\n'
#else
    #define debug(X) 3389
    #define debugL(Y) 3390
    #define debugP(Z) 3391
#endif

const i64 POW6 = 1000000;

void dfs(i64 v, vector<vector<i64>> &G, vector<i64> &deg, i64 &K, bool &stop){
    debugL(v);

    for(int nv : G.at(v)){
        if(nv == 0){
            continue;
        }
        if(deg.at(nv) <= 0){
            continue;
        }
        deg.at(nv)--;
        dfs(nv, G, deg, K, stop);
    }

    if(!stop){
        K++;
    }

    if(K > POW6){
        stop = true;
    }

    deg.at(v)--;
    return;
}

int main() {
    i64 N, M;
    cin >> N >> M;
    vector<vector<i64>> G(N);
    vector<i64> deg(N, 0);
    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G.at(u).emplace_back(v);
        G.at(v).emplace_back(u);
        deg.at(u)++;
        deg.at(v)++;
    }

    i64 K = 0;
    // vector<bool> seen(N, false);
    i64 r = 0;
    bool stop = false;
    dfs(r, G, deg, K, stop);

    cout << min(K, POW6) << '\n';
}