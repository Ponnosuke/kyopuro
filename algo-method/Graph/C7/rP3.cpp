#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << X << " "
    #define debugV(X) std::cerr << #X << " = " << X << ", "
    #define debugVL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugWL(Z) std::cerr << #Z << '\n'
    #define debugP() std::cerr << "Line:" << __LINE__ << '\n'
#else
    #define debug(X)
    #define debugV(X)
    #define debugVL(Y)
    #define debugWL(Z)
    #define debugP()
#endif

struct Edge{
    i64 from;
    i64 to;
    i64 leng;

    Edge(i64 ifrom, i64 ito, i64 ileng) : from(ifrom), to(ito), leng(ileng){
    }

    Edge(){
    }

    void Set(i64 ifrom, i64 ito, i64 ileng){
        from = ifrom;
        to = ito;
        leng = ileng;

        return;
    }
};

const i64 INF = (1LL << 60);

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<Edge>> G(N);
    for(int i = 0; i < M; i++){
        i64 u, v, w;
        cin >> u >> v >> w;

        G.at(u).emplace_back(Edge(u, v, w));
    }

    for(int i = 0; i < N; i++){
        i64 ret = INF;
        i64 dist = INF;

        debugVL(i);

        for(auto e : G.at(i)){
            debugV(e.leng);
            if(e.leng == dist){
                ret = min(ret, e.to);
            }
            else if(e.leng < dist){
                dist = e.leng;
                ret = e.to;
            }
        }

        debugWL();
        debugVL(ret);

        if(ret == INF){
            cout << -1 << '\n';
        }
        else{
            cout << ret << '\n';
        }

        debugWL();
    }
}