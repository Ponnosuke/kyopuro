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

/*
    Union-Find の実装 | アルゴ式 
    https://algo-method.com/descriptions/136 
*/
struct UnionFind {
    vector<int> par, rank, siz;

    // 構造体の初期化
    UnionFind(int n) : par(n,-1), rank(n,0), siz(n,1) { }

    // 根を求める
    int root(int x) {
        if (par[x]==-1) return x; // x が根の場合は x を返す
        else return par[x] = root(par[x]); // 経路圧縮
    }

    // x と y が同じグループに属するか (= 根が一致するか)
    bool issame(int x, int y) {
        return root(x)==root(y);
    }

    // x を含むグループと y を含むグループを併合する
    bool unite(int x, int y) {
        int rx = root(x), ry = root(y); // x 側と y 側の根を取得する
        if (rx==ry) return false; // すでに同じグループのときは何もしない
        // union by rank
        if (rank[rx]<rank[ry]) swap(rx, ry); // ry 側の rank が小さくなるようにする
        par[ry] = rx; // ry を rx の子とする
        if (rank[rx]==rank[ry]) rank[rx]++; // rx 側の rank を調整する
        siz[rx] += siz[ry]; // rx 側の siz を調整する
        return true;
    }

    // x を含む根付き木のサイズを求める
    int size(int x) {
        return siz[root(x)];
    }
};

struct Edge{
    int u;
    int v;
    int w;

    Edge(int iu, int iv, int iw) : u(iu), v(iv), w(iw) {
    }

    Edge(){
    }

    void Set(int iu, int iv, int iw){
        u = iu;
        v = iv;
        w = iw;

        return;
    }
};

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<Edge> edges(M, Edge());
    for(int i = 0; i < M; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges.at(i).Set(u, v, w);
    }

    auto less = [](Edge e1, Edge e2){
        return e1.w < e2.w;
    };
    sort(edges.begin(), edges.end(), less);

    UnionFind uf = UnionFind(N);
    int ans = 0;
    int cnt = 0;
    for(int i = 0; i < M; i++){
        Edge e = edges.at(i);
        if(uf.issame(e.u, e.v)){
            continue;
        }
        else{
            ans += e.w;
            uf.unite(e.u, e.v);
            cnt++;
        }

        if(cnt >= K){
            break;
        }
    }

    if(cnt >= K){
        cout << ans << endl;
    }
    else{
        cout << -1 << endl;
    }
}