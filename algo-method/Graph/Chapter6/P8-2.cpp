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

    vector<int> deg(N, 0);  // deg[v] := v の子頂点の数
    for(int i = 0; i < N; i++){
        deg.at(i) = children.at(i).size();
        if(deg.at(i) == 0){
            Q.emplace(i);
        }
    }

    vector<bool> isMatched(N, false);
    while(!Q.empty()){
        int v = Q.front();
        Q.pop();

        int par = parent.at(v);
        if(par == -1){
            continue;
        }

        if(!isMatched.at(v) && !isMatched.at(par)){
            isMatched.at(v) = true;
            isMatched.at(par) = true;
        }

        deg.at(par)--;
        if(deg.at(par) == 0){
            Q.emplace(par);
        }
    }

    int ans = 0;
    for(int i = 0; i < N; i++){
        if(isMatched.at(i)){
            debugL(i);
            ans++;
        }
    }

    cout << ans / 2 << endl;
}