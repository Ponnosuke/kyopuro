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

const int INF = (1 << 30);

int main() {
    int N, M;
    cin >> N >> M;
    vector<Edge> edges(M, Edge());
    for(int i = 0; i < M; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges.at(i).Set(u, v, -w);
    }

    vector<vector<int>> dStep(N, vector<int>(N, INF));  // dStep[k][v]
    dStep.at(0).at(0) = 0;
    for(int k = 1; k <= N-1; k++){
        dStep.at(k) = dStep.at(k-1);

        for(int i = 0; i < M; i++){
            Edge nowE = edges.at(i);
            if(dStep.at(k).at(nowE.from) != INF){
                dStep.at(k).at(nowE.to) = min(dStep.at(k).at(nowE.to), dStep.at(k).at(nowE.from) + nowE.w);
            }
        }
    }

    cout << -dStep.at(N-1).at(N-1) << '\n';
}