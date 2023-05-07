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

void dfs(int v, vector<vector<int>> &G, vector<bool> &seen, vector<int> &ans){
    seen.at(v) = true;
    ans.push_back(v);

    for(int nv : G.at(v)){
        if(seen.at(nv)){
            continue;
        }

        dfs(nv, G, seen, ans);
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
        G.at(a).push_back(b);
    }

    for(int i = 0; i < N; i++){
        sort(G.at(i).begin(), G.at(i).end());
    }

    vector<bool> seen(N, false);
    vector<int> ans;

    dfs(0, G, seen, ans);

    for(int i = 0; i < ans.size(); i++){
        cout << ans.at(i);

        if(i < (int)ans.size() - 1){
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}