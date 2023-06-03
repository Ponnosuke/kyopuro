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
    i64 N, M;
    cin >> N >> M;

    atcoder::dsu uf(N);
    for(int i = 0; i < M; i++){
        i64 u, v;
        cin >> u >> v;
        u--;
        v--;
        uf.merge(u, v);
    }
    i64 K;
    cin >> K;
    set<pair<i64, i64>> st;
    for(int i = 0; i < K; i++){
        i64 x, y;
        cin >> x >> y;
        x--;
        y--;

        i64 xl = uf.leader(x), yl = uf.leader(y);

        if(xl > yl){
            swap(xl, yl);
        }

        st.insert(make_pair(xl, yl));
    }

    i64 query;
    cin >> query;
    while(query--){
        i64 p, q;
        cin >> p >> q;

        p--;
        q--;
        i64 pl = uf.leader(p), ql = uf.leader(q);
        if(pl > ql){
            swap(pl, ql);
        }
        if(st.count(make_pair(pl, ql))){
            cout << "No" << '\n';
        }
        else{
            cout << "Yes" << '\n';
        }
    }
}