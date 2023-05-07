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

void dfs(int v, vector<vector<int>> &G, vector<bool> &seen, vector<int> &prev){
    seen.at(v) = true;
    for(int nv : G.at(v)){
        if(seen.at(nv)){
            continue;
        }

        prev.at(nv) =  v;
        dfs(nv, G, seen, prev);
    }

    return;
}

int main() {
    int N, M, s, t;
    cin >> N >> M >> s >> t;
    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        G.at(a).emplace_back(b);
    }

    vector<bool> seen(N, false);
    vector<int> prev(N, -1);
    dfs(s, G, seen, prev);
    vector<int> ans;
    int now = t;
    while(now != s){
        ans.emplace_back(now);
        now = prev.at(now);
    }
    ans.emplace_back(now);
    reverse(ans.begin(), ans.end());

    cout << (int)ans.size() << '\n';
    for(int i = 0; i < ans.size(); i++){
        cout << ans.at(i);
        if(i < ans.size() - 1){
            cout << " ";
        }
    }
    cout << '\n';
}