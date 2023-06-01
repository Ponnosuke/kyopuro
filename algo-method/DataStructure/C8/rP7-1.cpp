#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << X << " "
    #define debugV(X) std::cerr << #X << " = " << X << ", "
    #define debugVL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugWL(Z) std::cerr << #Z << '\n'
    #define debugP() std::cerr << "Line:" << __LINE__ << '\n'
#else
    #define debug(X)
    #define debugV(X)
    #define debugVL(Y)
    #define debugWL(Z)
    #define debugP()
#endif

int dfs(int v, vector<vector<int>> &children, vector<int> &memo){
    if(memo[v] != -1){
        return memo[v];
    }

    int ret = children[v].size();
    for(int nv : children[v]){
        ret += dfs(nv, children, memo);
    }

    memo[v] = ret;

    return ret;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 1; i < N; i++){
        cin >> A[i];
    }
    vector<vector<int>> children(N);
    for(int i = 1; i < N; i++){
        children[A[i]].push_back(i);
    }

    int Q;
    cin >> Q;

    vector<int> memo(N, -1);
    while(Q--){
        int v;
        cin >> v;
        cout << dfs(v, children, memo) << '\n';
    }
}