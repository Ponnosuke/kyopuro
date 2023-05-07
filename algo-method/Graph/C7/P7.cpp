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

const int INF = (1 << 30);

int main() {
    int N, M;
    cin >> N >> M;
    vector<Edge> edges(M);
    for(int i = 0; i < M; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges.at(i).Set(u, v, w);
    }

    vector<vector<int>> dStep(2*N + 1, vector<int>(N, INF));
    dStep.at(0).at(0) = 0;
    for(int k = 1; k <= N; k++){
        dStep.at(k) = dStep.at(k-1);
        for(int i = 0; i < M; i++){
            Edge now = edges.at(i);
            int u = now.from, v = now.to, w = now.w;
            if(dStep.at(k).at(u) < INF){
                dStep.at(k).at(v) = min(dStep.at(k).at(v), dStep.at(k).at(u) + w);
            }
        }
    }

    debugWL(point65);

    for(int i = 0; i < N; i++){
        if(dStep.at(N-1).at(i) != dStep.at(N).at(i)){
            dStep.at(N).at(i) = -INF;
        }
    }

    for(int k = N+1; k <= 2*N; k++){
        dStep.at(k) = dStep.at(k-1);
        for(int i = 0; i < M; i++){
            Edge now = edges.at(i);
            if(dStep.at(k).at(now.from) == -INF){
                dStep.at(k).at(now.to) = -INF;
            }
        }
    }

    int flag = dStep.at(2*N).at(N-1);
    if(flag == INF){
        cout << "impossible" << '\n';
    }
    else if(flag == -INF){
        cout << "-inf" << '\n';
    }
    else{
        cout << flag << '\n';
    }
}