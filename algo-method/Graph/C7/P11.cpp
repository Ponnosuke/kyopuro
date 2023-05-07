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
    int from;
    int leng;

    void Set(int f, int t, int l){
        from = f;
        to = t;
        leng = l;

        return;
    }

    Edge(){
    }

    Edge(int f, int t, int l) : from(f), to(t), leng(l) {
    }
};

const int INF = (1 << 30);

int main() {
    using pii = pair<int, int>;

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
    priority_queue< pii, vector<pii>, greater<pii> > pq;
    pq.push(make_pair(dist.at(0), 0));
    while(!pq.empty()){
        auto [d, v] = pq.top();
        pq.pop();

        if(done.at(v)){
            continue;
        }

        for(Edge ne : to.at(v)){
            int from = ne.from, to = ne.to, w = ne.leng;
            if(dist.at(to) > dist.at(from) + w){
                dist.at(to) = dist.at(from) + w;
                pq.push(make_pair(dist.at(to), to));
            }
        }

        done.at(v) = true;
    }

    for(int i = 0; i < N; i++){
        cout << dist.at(i) << '\n';
    }
}