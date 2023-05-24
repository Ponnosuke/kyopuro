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
    #define debugP() std::cerr << "Line:" << __LINE__ << '\n'
#else
    #define debug(X)
    #define debugV(X)
    #define debugVL(Y)
    #define debugWL(Z)
    #define debugP()
#endif

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> u(M), v(M);
    atcoder::dsu uf(N);
    for(int i = 0; i < M; i++){
        cin >> u.at(i) >> v.at(i);
        u.at(i)--;
        v.at(i)--;
        uf.merge(u.at(i), v.at(i));
    }

    vector<int> Edge(N, 0);
    for(int i = 0; i < M; i++){
        Edge.at(uf.leader(u.at(i)))++;
    }

    bool OK = true;
    for(int i = 0; i < N; i++){
        if(Edge.at(uf.leader(i)) != uf.size(i)){
            OK = false;
            break;
        }
    }

    cout << (OK ? "Yes" : "No") << endl;

    return 0;
}