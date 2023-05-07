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
    int cnt = 0;
    for(int nv : children.at(v)){
        dfs(nv, children, isChosen);

        if(!isChosen.at(nv)){
            cnt++;
        }
    }

    if(cnt >= 1){
        isChosen.at(v) = true;
    }

    return;
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    for(int i = 0; i < N-1; i++){
        int a, b;
        cin >> a >> b;
        G.at(a).emplace_back(b);
        G.at(b).emplace_back(a);
    }

    queue<int> Q;
    vector<bool> seen(N, false);
    int root = 0;
    Q.emplace(root);
    vector<vector<int>> children(N);
    seen.at(root) = true;
    while(!Q.empty()){
        int v = Q.front();
        Q.pop();
        for(int nv : G.at(v)){
            if(seen.at(nv)){
                continue;
            }

            children.at(v).emplace_back(nv);
            seen.at(nv) = true;
            Q.emplace(nv);
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

    return 0;
}