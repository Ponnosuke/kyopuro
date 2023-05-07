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

const int INF = 1000000000;

int main() {
    int N, M;
    cin >> N >> M;
    vector<Edge> E(M);
    for(int i = 0; i < M; i++){
        i64 u, v, w;
        cin >> u >> v >> w;
        E.at(i) = Edge(u, v, w);
    }

    vector<vector<i64>> d(N, vector<i64>(N, INF));
    d.at(0).at(0) = 0;
    i64 ans = 0;
    for(int i = 0; i < N; i++){
        if(i-1 >= 0){
            d.at(i) = d.at(i-1);
        }
        for(int j = 0; j < M; j++){
            Edge nowE = E.at(j);
            i64 from = nowE.from, to = nowE.to, w = nowE.leng;
            d.at(i).at(to) = min(d.at(i).at(to), d.at(i).at(from) + w);
        }

        if(i-1 >= 0){
            if(d.at(i-1) == d.at(i)){
                ans = i+1;
                break;
            }
        }
    }

    cout << ans << '\n';
}