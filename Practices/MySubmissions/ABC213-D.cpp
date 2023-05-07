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

void dfs(int v, vector<vector<int>> &G, vector<bool> &seen, vector<int> &ans){
    debugP(pointA);
    debugL(v);
    seen[v] = true;
    ans.push_back(v + 1);
    for(int nv : G[v]){
        if(seen[nv]){
            continue;
        }

        dfs(nv, G, seen, ans);

        debugP(pointB);
        debugL(v);
        ans.push_back(v + 1);
    }

    return;
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    for(int i = 0; i < N-1; i++){
        int A, B;
        cin >> A >> B;
        A--;
        B--;
        G[A].push_back(B);
        G[B].push_back(A);
    }

    for(int i = 0; i < N; i++){
        sort(G[i].begin(), G[i].end());
    }

    debugP(Graph);
    for(int i = 0; i < N; i++){
        debugL(i);
        for(int v : G[i]){
            debug(v);
        }
        debugP();
    }

    vector<bool> seen(N, false);
    vector<int> ans;
    dfs(0, G, seen, ans);

    int size = ans.size();
    for(int i = 0; i < size; i++){
        cout << ans[i];
        if(i < size - 1){
            cout << " ";
        }
    }
    cout << '\n';

    return 0;
}