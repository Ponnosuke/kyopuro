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

int main() {
    int N, s, K;
    cin >> N >> s >> K;
    vector<vector<int>> G(N);
    for(int i = 0; i < N-1; i++){
        int a, b;
        cin >> a >> b;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }

    vector<int> dist(N, -1);
    queue<int> Q;
    Q.emplace(s);
    dist[s] = 0;
    while(!Q.empty()){
        int v = Q.front();
        Q.pop();
        for(int nv : G[v]){
            if(dist[nv] != -1){
                continue;
            }

            dist[nv] = dist[v] + 1;
            Q.emplace(nv);
        }
    }

    int ans = 0;
    for(int i = 0; i < N; i++){
        if(dist[i] <= K && dist[i] % 2 == K % 2){
            ans++;
        }
    }

    cout << ans << endl;
}