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

const i64 MOD = 998244353;

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

    vector<i64> dp1(N, 1);  // dp1[v] := v を根とした部分木で v を選ぶときの元の数
    vector<i64> dp2(N, 1);  // dp2[v] := v を根とした部分木で v を選ばないときの元の数
    queue<i64> leaf;
    for(int i = 0; i < N; i++){
        if(deg.at(i) == 0){
            leaf.push(i);
        }
    }

    while(!leaf.empty()){
        i64 v = leaf.front();
        leaf.pop();

        for(i64 nv : children.at(v)){  // nv := v の子頂点
            dp1.at(v) *= (dp2.at(nv) % MOD);
            dp1.at(v) %= MOD;
            dp2.at(v) *= ((dp1.at(nv) + dp2.at(nv)) % MOD);
            dp2.at(v) %= MOD;
        }

        i64 p = parent.at(v);
        if(p == -1){
            continue;
        }
        deg.at(p)--;
        if(deg.at(p) == 0){
            leaf.push(p);
        }
    }

    cout << (dp1.at(root) + dp2.at(root)) % MOD << endl;
}