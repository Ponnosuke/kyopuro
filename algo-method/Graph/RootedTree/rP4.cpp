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

void dfs(int now, int cnt, const vector<vector<int>> &tree, vector<bool> &seen, vector<int> &dist){
    dist.at(now) = cnt;
    seen.at(now) = true;
    for(int next : tree.at(now)){
        if(seen.at(next)){
            continue;
        }

        dfs(next, cnt + 1, tree, seen, dist);
    }

    return;
}

int main() {
    int N;
    cin >> N;
    vector<int> P(N, 0);
    for(int i = 1; i < N; i++){
        cin >> P.at(i);
    }

    vector<vector<int>> tree(N);
    for(int i = 1; i < N; i++){
        tree.at(P.at(i)).emplace_back(i);
    }

    vector<bool> seen(N, false);
    vector<int> dist(N, 0);
    dfs(0, 0, tree, seen, dist);

    int ans = -1;
    for(int i = 0; i < N; i++){
        ans = max(ans, dist.at(i));
    }
    cout << ans << '\n';

    return 0;
}