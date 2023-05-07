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

void dfs(int v, vector<bool> &seen, vector<vector<int>> &G){
    seen.at(v) = true;
    cout << v << ' ';
    for(int nv : G.at(v)){
        if(seen.at(nv)){
            continue;
        }

        dfs(nv, seen, G);
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
    }

    for(int i = 0; i < N; i++){
        sort(G.at(i).begin(), G.at(i).end());
    }

    vector<bool> seen(N, false);
    seen.at(0) = 0;
    dfs(0, seen, G);
    cout << '\n';

    return 0;
}