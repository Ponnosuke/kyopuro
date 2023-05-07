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

    vector<vector<i64>> G(N);
    for(int i = 0; i < M; i++){
        i64 u, v;
        cin >> u >> v;
        u--;
        v--;


        G.at(u).push_back(v);
        G.at(v).push_back(u);
    }

    queue<i64> Q;
    vector<bool> seen(N, false);
    bool OK = true;
    atcoder::dsu uf(N);
    map<i64, set<i64>> mp;
    for(i64 i = 0; i < N; i++){
        if(seen.at(i)){
            continue;
        }

        seen.at(i) = true;
        i64 r_cnt = 0, minus_cnt = 0;

        debugVL(i);

        Q.push(i);

        while(!Q.empty()){
            i64 v = Q.front();
            Q.pop();

            debugVL(v);

            for(i64 nv : G.at(v)){
                debugVL(nv);
                minus_cnt++;


                if(uf.same(v, nv)){
                    r_cnt++;
                }

                uf.merge(v, nv);

                if(seen.at(nv)){
                    continue;
                }
                seen.at(nv) = true;
                Q.push(nv);
            }

        }

        debugVL(r_cnt);
        debugVL(minus_cnt);
        r_cnt -= (minus_cnt)/2;

        if(r_cnt != 1){
            OK = false;
            break;
        }
    }

    cout << (OK ? "Yes" : "No") << '\n';

    return 0;
}