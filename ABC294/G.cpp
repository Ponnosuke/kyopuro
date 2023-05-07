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
    i64 N;
    cin >> N;
    vector<vector<Edge>> G(N);
    for(int i = 0; i < N-1; i++){
        i64 u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        G.at(u).emplace_back(Edge(u, v, w));
        G.at(v).emplace_back(Edge(v, u, w));
    }
}