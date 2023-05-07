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

struct Edge {
    int from;
    int to;
    int w;

    void Set(int _from, int _to, int _w){
        from = _from;
        to = _to;
        w = _w;

        return;
    }

    Edge(int _from, int _to, int _w) : from(_from), to(_to), w(_w) {
    }

    Edge(){
    }

};

const int INF = 1000000000;

int main() {
    int N, M;
    cin >> N >> M;
    vector<Edge> edges(M, Edge(0,0,0));
    for(int i = 0; i < M; i++){
        int u, v, w;
        cin >> u >> v >> w;

        Edge e = Edge(u, v, w);
        edges.at(i) = e;
    }

    vector<vector<int>> d(N, vector<int>(N, INF));
    int ans = -1;
    d.at(0).at(0) = 0;
    for(int k = 1; k <= N-1; k++){
        d.at(k) = d.at(k-1);

        for(int i = 0; i < M; i++){
            Edge e = edges.at(i);

            d.at(k).at(e.to) = min(d.at(k).at(e.to), d.at(k).at(e.from) + e.w);
        }

        if(d.at(k) == d.at(k-1)){
            ans = k;
            break;
        }
    }

    cout << ans << '\n';
}