#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << X << " "
    #define debugV(X) std::cerr << #X << " = " << X << ", "
    #define debugVL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugWL(Z) std::cerr << #Z << '\n'
#else
    #define debug(X)
    #define debugV(X)
    #define debugVL(Y)
    #define debugWL(Z)
#endif

const i64 INF = (1LL << 62);

int main() {
    int N;
    cin >> N;
    vector<vector<i64>> G(N);
    for(int i = 0; i < N-1; i++){
        i64 a, b;
        cin >> a >> b;
        G.at(a).push_back(b);
        G.at(b).push_back(a);
    }
    vector<i64> w(N);
    for(int i = 0; i < N; i++){
        cin >> w.at(i);
    }

    vector<vector<i64>> children(N);
    vector<i64> parent(N, -1);
    vector<bool> seen(N, false);
    vector<i64> deg(N, 0);  // deg[i] := i の子頂点の数
    queue<i64> Q;
    i64 root = 0;
    Q.push(root);
    while(!Q.empty()){
        i64 v = Q.front();
        Q.pop();
        for(i64 nv : G.at(v)){
            if(seen.at(nv)){
                continue;
            }

            children.at(v).push_back(nv);
            deg.at(v)++;
            parent.at(nv) = v;
            seen.at(nv) = true;
            Q.push(nv);
        }
    }

    queue<i64> leaf;
    for(int i = 0; i < N; i++){
        if(deg.at(i) == 0){
            leaf.push(i);
        }
    }

    vector<bool> isChosen(N, false);
    while(!leaf.empty()){
        i64 v = leaf.front();
        leaf.pop();
        bool flag = false;
        for(i64 nv : children.at(v)){
            flag |= isChosen.at(nv);
        }
        
        isChosen.at(v) = !flag;
        i64 p = parent.at(v);
        deg.at(p)--;
        if(deg.at(p) == 0){
            leaf.push(p);
        }
    }

    i64 ans = 0;
    debugWL(vertexes);
    for(int i = 0; i < N; i++){
        if(isChosen.at(i)){
            debug(i);
            ans += w.at(i);
        }
    }
    debugWL();

    cout << ans << endl;
}