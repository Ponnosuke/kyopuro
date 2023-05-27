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

void dfs(int v, vector<int> &dist, vector<int> &L, vector<vector<int>> &G, vector<int> &dig){
    for(int nv : G.at(v)){
        if(dist.at(nv) != -1){
            continue;
        }

        dist.at(nv) = dist.at(v) + 1;
        if(dist.at(nv) % 3 == 1){
            L.push_back(dig.at(nv));
        }

        dfs(nv, dist, L, G, dig);
    }

    return;
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    vector<int> dig(N, 0);
    for(int i = 0; i < N-1; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G.at(u).push_back(v);
        G.at(v).push_back(u);
        dig.at(u)++;
        dig.at(v)++;
    }

    int start = -1;
    for(int i = 0; i < N; i++){
        if(dig.at(i) == 1){
            start = i;
            break;
        }
    }

    vector<int> dist(N, -1);
    dist.at(start) = 0;
    vector<int> L;

    dfs(start, dist, L, G, dig);

    sort(L.begin(), L.end());
    for(int i = 0; i < L.size(); i++){
        cout << L.at(i);

        if(i < (int)L.size() - 1){
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}