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
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    vector<int> outDeg(N, 0);
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        G[b].push_back(a);
        outDeg[a]++;
    }

    for(int i = 0; i < N; i++){
        sort(G[i].begin(), G[i].end());
    }

    queue<int> Q;
    for(int i = 0; i < N; i++){
        if(outDeg[i] == 0){
            Q.push(i);
        }
    }

    vector<int> ans;
    while(!Q.empty()){
        int v = Q.front();
        debugVL(v);
        Q.pop();
        ans.push_back(v);
        for(int nv : G[v]){
            debugV(nv);
            outDeg[nv]--;
            if(outDeg[nv] == 0){
                Q.push(nv);
            }
        }
        debugW();
    }

    debugW(ans);
    for(int i = 0; i < N; i++){
        debug(ans.at(i));
    }

    reverse(ans.begin(), ans.end());

    for(int i = 0; i < N; i++){
        cout << ans[i];
        if(i < N-1){
            cout << " ";
        }
    }
    cout << '\n';
}