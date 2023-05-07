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
    vector<int> deg(N, 0);  // deg[i] := i の子頂点の数
    vector<int> parent(N, -1);
    while(!Q.empty()){
        int v = Q.front();
        Q.pop();
        for(int nv : G.at(v)){
            if(seen.at(nv)){
                continue;
            }

            children.at(v).emplace_back(nv);
            deg.at(v)++;
            parent.at(nv) = v;
            seen.at(nv) = true;
            Q.emplace(nv);
        }
    }

    for(int i = 0; i < N; i++){
        if(deg.at(i) == 0){
            Q.emplace(i);
        }
    }

    vector<bool> isChosen(N, false);
    while(!Q.empty()){
        int v = Q.front();
        Q.pop();
        int cnt = 0;
        for(int nv : children.at(v)){
            if(!isChosen.at(nv)){
                cnt++;
            }

        }
        if(cnt >= 1){
            isChosen.at(v) = true;
        }

        int p = parent.at(v);
        if(p == -1){
            continue;
        }
        deg.at(p)--;
        if(deg.at(p) == 0){
            Q.emplace(p);
        }
    }

    int ans = 0;
    for(int i = 0; i < N; i++){
        if(isChosen.at(i)){
            ans++;
            debugL(i);
        }
    }

    cout << ans << endl;
}