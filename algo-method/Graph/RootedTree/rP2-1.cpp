/*
    TLE
*/

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

vector<bool> seen(10010, false);
vector<int> ans(10010, 0);

void dfs(int v, vector<vector<int>> tree, int &index){
    seen[v] = true;
    ans[index] = v;
    for(int nv : tree[v]){
        if(seen[nv]){
            continue;
        }

        index++;
        dfs(nv, tree, index);
    }

    return;
}

int main() {
    int N;
    cin >> N;
    vector<int> P(N);
    for(int i = 1; i < N; i++)  cin >> P[i];

    vector<vector<int>> tree(N);
    for(int i = 1; i < N; i++){
        tree[P[i]].push_back(i);
    }

    debugP(point46);

    vector<bool> seen(N, false);
    seen[0] = true;
    int index = 0;
    dfs(0, tree, index);

    debugP(point53);

    for(int i = 0; i < N; i++){
        debugL(i);

        cout << ans[i];
        if(i < N-1){
            cout << " ";
        }
    }
    cout << '\n';
}