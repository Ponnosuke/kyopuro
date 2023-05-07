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
    seen.at(root) = true;
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

    debugWL(deg);
    for(int i = 0; i < N; i++){
        debugVL(i);
        debugVL(deg.at(i));
    }
    debugWL();

    debugWL(leaf);
    queue<i64> leaf;
    for(int i = 0; i < N; i++){
        if(deg.at(i) == 0){
            debugV(i);
            leaf.push(i);
        }
    }
    debugWL();

    debugWL(leafLoop);
    vector<i64> dp1(N, 0);  // dp1[v] := v を根とした部分木で v を選ぶときの最大値
    vector<i64> dp2(N, 0);  // dp2[v] := v を根とした部分木で v を選ばないときの最大値
    while(!leaf.empty()){
        i64 v = leaf.front();
        leaf.pop();
        dp1.at(v) = w.at(v);
        dp2.at(v) = 0;
        debugVL(v);
        for(i64 nv : children.at(v)){  // nv := v の子頂点
            debugWL(routeFor);
            debugV(nv);
            dp1.at(v) += dp2.at(nv);
            dp2.at(v) += max(dp1.at(nv), dp2.at(nv));
        }
        debugWL();

        i64 p = parent.at(v);
        if(p == -1){
            continue;
        }
        deg.at(p)--;
        if(deg.at(p) == 0){
            leaf.push(p);
        }
    }
    debugWL();

    debugWL(dp);
    for(int i = 0; i < N; i++){
        debugVL(i);
        debugV(dp1.at(i));
        debugVL(dp2.at(i));
    }
    debugWL();

    cout << max(dp1.at(root), dp2.at(root)) << endl;
}