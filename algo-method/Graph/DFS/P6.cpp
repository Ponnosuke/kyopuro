#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
  #define debug(X) std::cerr << #X << " = " << X << ", "
  #define debugL(Y) std::cerr << #Y << " = " << Y << '\n'
  #define debugP(Z) std::cerr << #Z << '\n'
#else
  #define debug(X) 3389
  #define debugL(Y) 3390
  #define debugP(Z) 3391
#endif

void dfs(int v, vector<vector<int>> &G, vector<bool> &seen){
    seen.at(v) = true;
    for(int nv : G.at(v)){
        if(seen.at(nv)){
            continue;
        }

        dfs(nv, G, seen);
    }

    return;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        G.at(a).emplace_back(b);
        G.at(b).emplace_back(a);
    }

    vector<bool> seen(N, false);
    int ans = 0;
    for(int i = 0; i < N; i++){
        if(!seen.at(i)){
            ans++;
            dfs(i, G, seen);
        }
    }

    cout << ans << '\n';

    return 0;
}