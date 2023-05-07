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
    int to;
    int w;

    Edge(int _to, int _w) : to(_to), w(_w){
    }
};

const int INF = (1 << 30);

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<Edge>> G(N);
    for(int i = 0; i < M; i++){
        int u, v, w;
        cin >> u >> v >> w;
        Edge e = Edge(v, w);
        G.at(u).push_back(e);
    }

    vector<int> dist(N, INF);
    dist.at(0) = 0;
    for(int i = 0; i < N; i++){
        for(auto e : G.at(i)){
            dist.at(e.to) = min(dist.at(e.to), dist.at(i) + e.w);
        }
    }

    if(dist.at(N-1) == INF){
        cout << -1 << '\n';
    }
    else{
        cout << dist.at(N-1) << '\n';
    }
}