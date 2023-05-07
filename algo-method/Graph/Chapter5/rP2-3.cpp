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

void dfs(int now, int end, vector<vector<int>> &G, vector<bool> &seen, bool &stop, deque<int> &ans){
    seen.at(now) = true;
    if(!stop){
        ans.push_back(now);
    }
    if(now == end){
        stop = true;
    }
    for(int nv : G.at(now)){
        if(seen.at(nv)){
            continue;
        }

        dfs(nv, end, G, seen, stop, ans);
    }

    if(!stop){
        ans.pop_back();
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
    bool stop = false;
    deque<int> ans;
    dfs(s, t, G, seen, stop, ans);

    cout << (int)ans.size() << '\n';
    for(int i = 0; i < ans.size(); i++){
        cout << ans.at(i);
        if(i < ans.size() - 1){
            cout << " ";
        }
    }
    cout << '\n';

    return 0;
}