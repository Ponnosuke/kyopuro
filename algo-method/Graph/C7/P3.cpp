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
    int to;
    int w;

    Edge(int _to, int _w) : to(_to), w(_w) {
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

    for(int i = 0; i < N; i++){
        int ans = -1, flag = INF;
        for(auto e : G.at(i)){
            if(flag > e.w ){
                ans = e.to;
                flag = e.w;
            }
            else if(flag == e.w){
                ans = min(ans, e.to);
            }
        }

        cout << ans << '\n';
    }
}