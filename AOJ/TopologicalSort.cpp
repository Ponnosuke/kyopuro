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
    int V, E;
    cin >> V >> E;
    vector<vector<int>> G(V);
    vector<int> inDeg(V, 0);
    for(int i = 0; i < E; i++){
        int s, t;
        cin >> s >> t;
        G[s].push_back(t);
        inDeg[t]++;
    }

    queue<int> Q;
    for(int i = 0; i < V; i++){
        if(inDeg[i] == 0){
            Q.push(i);
        }
    }

    vector<int> ans;
    while(!Q.empty()){
        int v = Q.front();
        Q.pop();
        ans.push_back(v);
        for(int nv : G[v]){
            inDeg[nv]--;
            if(inDeg[nv] == 0){
                Q.push(nv);
            }
        }
    }

    for(int i = 0; i < V; i++){
        cout << ans[i] << '\n';
    }
}