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
    int N;
    cin >> N;
    vector<int> P(N);
    for(int i = 1; i < N; i++){
        cin >> P.at(i);
    }

    vector<vector<int>> tree(N);
    for(int i = 1; i < N; i++){
        tree.at(P.at(i)).emplace_back(i);
    }

    vector<int> ans(N, 0);
    vector<bool> seen(N, false);
    queue<int> Q;
    Q.emplace(0);
    seen.at(0) = true;
    while(!Q.empty()){
        int v = Q.front();
        Q.pop();
        for(int nv : tree.at(v)){
            if(seen.at(nv)){
                continue;
            }

            seen.at(nv) = true;
            ans.at(nv) = ans.at(v) + 1;
            Q.emplace(nv);
        }
    }

    for(int i = 0; i < N; i++){
        cout << ans.at(i) << '\n';
    }
}