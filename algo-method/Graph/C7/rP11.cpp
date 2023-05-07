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
    vector<vector<Edge>> to(N);
    for(int i = 0; i < M; i++){
        int u, v, w;
        cin >> u >> v >> w;
        to.at(u).push_back(Edge(u, v, w));
    }

    vector<int> dist(N, INF);
    dist.at(0) = 0;
    vector<bool> done(N, false);
    priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    pq.emplace(make_pair(dist.at(0), 0));
    while(!pq.empty()){
        auto [d, v] = pq.top();
        pq.pop();

        if(done.at(v)){
            continue;
        }

        for(auto e : to.at(v)){
            if(dist.at(e.to) > dist.at(v) + e.w){
                dist.at(e.to) = dist.at(v) + e.w;
                pq.emplace(dist.at(e.to), e.to);
            }
        }

        done.at(v) = true;
    }

    for(int i = 0; i < N; i++){
        cout << dist.at(i) << '\n';
    }
}