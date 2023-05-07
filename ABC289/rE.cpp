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

int main() {
    int T;
    cin >> T;
    while(T--){
        int N, M;
        cin >> N >> M;
        vector<int> C(N);
        for(int i = 0; i < N; i++){
            cin >> C.at(i);
        }
        vector<vector<int>> G(N);
        for(int i = 0; i < M; i++){
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            G.at(u).push_back(v);
            G.at(v).push_back(u);
        }

        queue<pair<int, int>> Q;
        vector<vector<int>> dist(N, vector<int>(N, -1));
        dist.at(0).at(N-1) = 0;
        Q.emplace(make_pair(0, N-1));
        while(!Q.empty()){
            auto [v, u] = Q.front();
            Q.pop();

            for(int nv : G.at(v)){
                for(int nu : G.at(u)){
                    if(C.at(nv) == C.at(nu)){
                        continue;
                    }
                    if(dist.at(nv).at(nu) != -1){
                        continue;
                    }

                    dist.at(nv).at(nu) = dist.at(v).at(u) + 1;
                    Q.emplace(make_pair(nv, nu));
                }
            }
        }

        cout << dist.at(N-1).at(0) << '\n';
    }

    return 0;
}