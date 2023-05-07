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

void dfs(int v, vector<vector<int>> &G, vector<bool> &seen, stack<int> &ans){
    seen.at(v) = true;
    for(int nv : G.at(v)){
        if(seen.at(nv)){
            continue;
        }

        dfs(nv, G, seen, ans);
    }

    ans.emplace(v);

    return;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;

        G.at(a).emplace_back(b);
    }

    for(int i = 0; i < N; i++){
        sort(G.at(i).begin(), G.at(i).end());
    }

    stack<int> ans;
    vector<bool> seen(N, false);
    for(int i = 0; i < N; i++){
        if(seen.at(i)){
            continue;
        }

        dfs(i, G, seen, ans);
    }

    int ansSize = ans.size();
    for(int i = 0; i < ansSize; i++){
        int tmp = ans.top();
        ans.pop();
        cout << tmp;
        if(i < ansSize - 1){
            cout << " ";
        }
    }
    cout << '\n';

    return 0;
}