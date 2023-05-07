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

int getIndex(int i, int j, int H, int W){
    return j + i*W;
}

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W-1, 0)), B(H-1, vector<int>(W, 0));

    // debugWL(pointA1);

    int sumW = 0;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W-1; j++){
            cin >> A.at(i).at(j);
            sumW += A.at(i).at(j);
        }
    }
    for(int i = 0; i < H-1; i++){
        for(int j = 0; j < W; j++){
            cin >> B.at(i).at(j);
            sumW += B.at(i).at(j);
        }
    }

    debugWL(pointA);

    int index = 0;
    vector<Edge> edges((H-1) * W + H * (W-1), Edge());
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(j <= W-2){
                edges.at(index).Set(getIndex(i, j, H, W), getIndex(i, j+1, H, W), A.at(i).at(j));
                index++;
            }
            if(i <= H-2){
                edges.at(index).Set(getIndex(i, j, H, W), getIndex(i+1, j, H, W), B.at(i).at(j));
                index++;
            }
        }
    }

    auto greater = [](Edge e1, Edge e2){
        return e1.w > e2.w;
    };
    sort(edges.begin(), edges.end(), greater);

    debugWL(pointB);
    debugVL(index);

    int GW = 0;
    UnionFind uf = UnionFind(index);
    for(int i = 0; i < index; i++){
        Edge e = edges.at(i);
        debugVL(i);
        debugV(e.u);
        debugVL(e.v);

        if(uf.issame(e.u, e.v)){
            continue;
        }
        else{
            GW += e.w;
            debugWL(routeB);
            debugVL(i);
            debugV(e.u);
            debugVL(e.v);
            uf.unite(e.u, e.v);
        }
    }

    debugWL(pointC);
    debugV(sumW);
    debugVL(GW);

    cout << sumW - GW << endl;
}