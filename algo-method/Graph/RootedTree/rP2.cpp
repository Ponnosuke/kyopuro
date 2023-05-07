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

void dfs(int v, const vector<vector<int>> &tree, vector<bool> &seen, vector<int> &ans){
    seen[v] = true;
    ans.push_back(v);

    for(int nv : tree[v]){
        if(seen[nv]){
            continue;
        }

        dfs(nv, tree, seen, ans);
    }

    return;
}

int main() {
    int N;
    cin >> N;
    vector<int> P(N);
    for(int i = 1; i < N; i++)  cin >> P[i];

    debugP(point43);
    debugL(tree.size());

    vector<vector<int>> tree(N);
    for(int i = 1; i < N; i++){
        debugL(i);
        debugL(P[i]);

        tree[P[i]].push_back(i);

        debugL(i);
    }

    debugP(point50);

    vector<bool> seen(N, false);
    vector<int> ans;
    seen[0] = true;
    dfs(0, tree, seen, ans);

    int ansSize = ans.size();
    for(int i = 0; i < ansSize; i++){
        cout << ans[i];
        if(i < ansSize - 1){
            cout << " ";
        }
    }
    cout << '\n';
}