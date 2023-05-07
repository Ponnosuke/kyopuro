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

void dfs(int v, vector<vector<int>> &children, vector<bool> &isChosen){
    bool flag = false;

    for(int nv : children.at(v)){
        dfs(nv, children, isChosen);

        flag |= isChosen.at(nv);
    }

    isChosen.at(v) = !flag;
    return;
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    for(int i = 0; i < N-1; i++){
        int a, b;
        cin >> a >> b;
        G.at(a).push_back(b);
        G.at(b).push_back(a);
    }

    vector<vector<int>> children(N);
    vector<bool> seen(N, false);
    queue<int> Q;
    int root = 0;
    Q.push(root);
    seen.at(root) = true;
    while(!Q.empty()){
        int v = Q.front();
        Q.pop();
        for(int nv : G.at(v)){
            if(seen.at(nv)){
                continue;
            }

            children.at(v).push_back(nv);
            seen.at(nv) = true;
            Q.push(nv);
        }
    }

    vector<bool> isChosen(N, false);
    dfs(root, children, isChosen);

    int ans = 0;
    for(int i = 0; i < N; i++){
        if(isChosen.at(i)){
            ans++;
        }
    }

    cout << ans << endl;
}