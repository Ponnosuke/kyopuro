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

int dfs(int v, const vector<vector<int>> &tree, vector<bool> &seen, vector<int> &ans){
    seen.at(v) = true;

    for(int nv : tree.at(v)){
        if(seen.at(nv)){
            continue;
        }

        ans.at(v) += (dfs(nv, tree, seen, ans) + 1);
    }

    return ans.at(v);
}

int main() {
    int N;
    cin >> N;
    vector<int> P(N, 0);
    for(int i = 1; i < N; i++){
        cin >> P.at(i);
    }

    vector<vector<int>> tree(N);
    for(int i = 1; i < N; i++){
        tree.at(P.at(i)).emplace_back(i);
    }

    vector<int> ans(N, 0);
    vector<bool> seen(N, false);

    dfs(0, tree, seen, ans);

    for(int i = 0; i < N; i++){
        cout << ans.at(i) << '\n';
    }
}