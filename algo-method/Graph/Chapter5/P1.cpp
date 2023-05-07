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

int main() {
    int N, M, s, t;
    cin >> N >> M >> s >> t;
    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        G.at(a).emplace_back(b);
    }

    vector<bool> visited(N, false);
    queue<int> Q;
    visited.at(s) = true;
    Q.emplace(s);
    while(!Q.empty()){
        int v = Q.front();
        visited.at(v) = true;
        Q.pop();
        for(int nv : G.at(v)){
            if(visited.at(nv)){
                continue;
            }

            Q.emplace(nv);
        }
    }

    cout << (visited.at(t) ? "Yes" : "No") << endl;
}