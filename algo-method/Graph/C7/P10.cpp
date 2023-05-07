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

struct Edge{
    int from;
    int to;
    int w;

    void Set(int _from, int _to, int _w){
        from = _from;
        to = _to;
        w = _w;

        return;
    }

    Edge(){
    }

    Edge(int _from, int _to, int _w) : from(_from), to(_to), w(_w) {        
    }
};

int INF = 1000000000;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<Edge>> to(N);
    for(int i = 0; i < M; i++){
        int u, v, w;
        cin >> u >> v >> w;
        to.at(u).push_back(Edge(u, v, w));
    }

    vector<int> dist(N, INF);
    vector<bool> done(N, false);
    dist.at(0) = 0;

    while(true){
        int v = -1, d = 2 * INF;
        for(int i = 0; i < N; i++){
            if(!done.at(i)){
                if(d > dist.at(i)){
                    d = dist.at(i);
                    v = i;
                }
            }
        }

        if(v == -1){
            break;
        }

        for(Edge ne : to.at(v)){
            dist.at(ne.to) = min(dist.at(ne.to), dist.at(v) + ne.w);
        }

        done.at(v) = true;
    }

    for(int i = 0; i < N; i++){
        cout << dist.at(i) << '\n';
    }
}