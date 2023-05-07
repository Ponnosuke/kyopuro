#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << X << " "
    #define debugV(X) std::cerr << #X << " = " << X << ", "
    #define debugVL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugWL(Z) std::cerr << #Z << '\n'
#else
    #define debug(X)
    #define debugV(X)
    #define debugVL(Y)
    #define debugWL(Z)
#endif

int main() {
    int N, M;
    cin >> N >> M;
    // vector<vector<int>> G(N);
    atcoder::dsu uf(N);
    bool OK = true;
    vector<int> deg(N, 0);
    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;

        if(uf.same(u, v)){
            OK = false;
            break;
        }

        uf.merge(u, v);
        deg.at(u)++;
        deg.at(v)++;
    }

    for(int i = 0; i < N; i++){
        if(deg.at(i) == 1 || deg.at(i) == 2){
            continue;
        }
        else{
            OK = false;
            break;
        }
    }

    cout << (OK ? "Yes" : "No") << '\n';
}