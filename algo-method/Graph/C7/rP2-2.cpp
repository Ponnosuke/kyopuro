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
    i64 N, M;
    cin >> N >> M;
    vector<i64> u(M), v(M), w(M);
    for(int i = 0; i < M; i++){
        cin >> u.at(i) >> v.at(i) >> w.at(i);
    }
    vector<vector<Edge>> toG(N);
    for(int i = 0; i < M; i++){
        toG.at(u.at(i)).emplace_back(Edge(u.at(i), v.at(i), w.at(i)));
    }

    vector<i64> dist(N, INF);
    dist.at(0) = 0;
    for(int i = 0; i < N; i++){
        for(auto e : toG.at(i)){
            i64 from = e.from, to = e.to, leng = e.leng;

            dist.at(to) = min(dist.at(to), dist.at(from) + leng);
        }
    }

    if(dist.at(N-1) == INF){
        cout << -1 << endl;
    }
    else{
        cout << dist.at(N-1) << endl;
    }
}