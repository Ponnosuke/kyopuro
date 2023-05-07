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

void dfs(int v, vector<vector<int>> &children, vector<int> &parent, vector<bool> &isMatched){
    for(int nv : children.at(v)){
        dfs(nv, children, parent, isMatched);
    }

    if(parent.at(v) == -1){
        return;
    }

    if(!isMatched.at(v) && !isMatched.at(parent.at(v))){
        isMatched.at(v) = true;
        isMatched.at(parent.at(v)) = true;
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

    int root = 0;
    vector<vector<int>> children(N);
    vector<int> parent(N, -1);
    queue<int> Q;
    vector<int> seen(N, false);
    Q.emplace(root);
    seen.at(root) = true;
    while(!Q.empty()){
        int v = Q.front();
        Q.pop();
        for(int nv : G.at(v)){
            if(seen.at(nv)){
                continue;
            }

            children.at(v).emplace_back(nv);
            parent.at(nv) = v;
            seen.at(nv) = true;
            Q.emplace(nv);
        }
    }

    vector<bool> isMatched(N, false);
    dfs(root, children, parent, isMatched);

    int ans = 0;
    for(int i = 0; i < N; i++){
        if(isMatched.at(i)){
            debugL(i);
            ans++;
        }
    }

    cout << ans / 2 << endl;
}