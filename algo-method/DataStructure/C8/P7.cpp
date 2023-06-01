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

map<int, int> memo;

int dfs(int v, vector<vector<int>> &children){
    if(memo.count(v)){
        return memo.at(v);
    }

    int ret = children.at(v).size();
    for(int nv : children.at(v)){
        ret += dfs(nv, children);
    }

    memo[v] = ret;

    return ret;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 1; i < N; i++){
        cin >> A.at(i);
    }
    vector<vector<int>> children(N);
    for(int i = 1; i < N; i++){
        children.at(A.at(i)).push_back(i);
    }

    int Q;
    cin >> Q;

    while(Q--){
        int v;
        cin >> v;
        cout << dfs(v, children) << '\n';
    }
}