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

    // Edge(int _from, int _to, int _w) : from(_from), to(_to), w(_w) {
    // }
};

const int INF = 1000000000;

int main() {
    int N, M;
    cin >> N >> M;
    vector<Edge> edges(M);
    for(int i = 0; i < M; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges.at(i).Set(u, v, w);
    }

    vector<int> d(N, INF);
    d.at(0) = 0;
    for(int i = 0; i < M; i++){
        Edge nowE = edges.at(i);
        int u = nowE.from, v = nowE.to, w = nowE.w;

        d.at(v) = min(d.at(v), d.at(u) + w);
    }

    for(int i = 0; i < N; i++){
        cout << d.at(i) << endl;
    }
}