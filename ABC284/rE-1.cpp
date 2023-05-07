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

const int E6 = 1000000;

void dfs(int v, vector<vector<int>> &G, vector<bool> &seen, int &K){
    if(K >= E6){
        return;
    }
    K++;
    seen[v] = true;

    for(int nv : G[v]){
        if(seen[nv]){
            continue;
        }

        dfs(nv, G, seen, K);
    }

    seen[v] = false;

    return;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<bool> seen(N, false);
    int K = 0;
    dfs(0, G, seen, K);

    cout << min(K, E6) << '\n';

    return 0;
}