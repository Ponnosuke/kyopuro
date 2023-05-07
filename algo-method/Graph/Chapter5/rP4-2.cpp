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

void dfs(int v, vector<vector<int>> &G, vector<int> &color, bool &OK){
    for(int nv : G.at(v)){
        if(color.at(nv) != -1){
            if(color.at(nv) == color.at(v)){
                OK = false;
            }

            continue;
        }

        color.at(nv) = 1 - color.at(v);
        dfs(nv, G, color, OK);
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

    vector<int> color(N, -1);  // 1: black, 2: white
    bool OK = true;
    for(int i = 0; i < N; i++){
        if(color.at(i) != -1){
            continue;
        }

        color.at(i) = 1;
        dfs(i, G, color, OK);
    }

    cout << (OK ? "Yes" : "No") << '\n';
}