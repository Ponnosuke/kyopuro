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

    vector<int> cntV(N, 0), cntE(N, 0);

    for(int v = 0; v < N; v++){
        int lv = uf.leader(v);
        cntV.at(lv)++;
    }

    for(int i = 0; i < M; i++){
        int ev = uf.leader(u.at(i));
        cntE.at(ev)++;
    }

    if(cntV == cntE){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}