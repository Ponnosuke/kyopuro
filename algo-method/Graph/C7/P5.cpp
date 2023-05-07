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

    // Edge(){
    // }

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

    vector<int> d(N, INF), prev_d = d;
    bool stop = false;
    int ans = 0;
    d.at(0) = 0;

    debugWL(DEBUG);
    debugWL(point61);

    while(!stop){
        ans++;

        for(int i = 0; i < M; i++){
            Edge e = edges.at(i);

            d.at(e.to) = min(d.at(e.to), d.at(e.from) + e.w);
        }

        if(d == prev_d){
            stop = true;
            break;
        }
        else{
            prev_d = d;
        }
    }

    cout << ans << '\n';
}