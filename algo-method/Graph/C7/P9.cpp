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
        edges.at(i).Set(u, v, w);
    }

    vector<vector<int>> dStep(N, vector<int>(N, INF));
    dStep.at(0).at(0) = 0;
    vector<int> pre(N, 0); // pre[v] := 頂点 v の前の頂点
    for(int k = 1; k <= N-1; k++){
        dStep.at(k) = dStep.at(k-1);

        for(int i = 0; i < M; i++){
            Edge now = edges.at(i);
            if(dStep.at(k).at(now.from) != INF){
                if( dStep.at(k).at(now.to) > (dStep.at(k).at(now.from) + now.w) ){
                    dStep.at(k).at(now.to) = dStep.at(k).at(now.from) + now.w;
                    pre.at(now.to) = now.from;
                }
            }
        }
    }

    int now = N-1;
    stack<int> ans;
    ans.push(now);
    while(now != 0){
        now = pre.at(now);
        ans.push(now);
    }

    cout << (int)ans.size() << '\n';
    while(!ans.empty()){
        cout << ans.top();
        ans.pop();
        if(!ans.empty()){
            cout << " ";
        }
        else{
            cout << '\n';
        }
    }
}