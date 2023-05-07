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
        if(v != u){
            G.at(v).push_back(u);
        }

    }

    queue<i64> Q;
    vector<bool> seen(N, false);
    map<i64, set<i64>> mp;
    i64 cnt_v = 0, cnt_e = 0;
    bool OK = true;
    for(int i = 0; i < N; i++){
        if(seen.at(i)){
            continue;
        }

        debugVL(i);

        cnt_v = 0, cnt_e = 0;

        seen.at(i) = true;

        Q.push(i);

        while(!Q.empty()){
            i64 v = Q.front();
            Q.pop();
            cnt_v++;

            debugVL(v);

            for(i64 nv : G.at(v)){
                cnt_e++;
                if(mp[v].count(nv)){
                    continue;
                }
                mp[v].insert(nv);
                if(v != nv){
                    mp[nv].insert(v);
                }
                debugVL(nv);
                if(seen.at(nv)){
                    continue;
                }


                seen.at(nv) = true;
                Q.push(nv);
            }
        }

        debugV(cnt_v);
        debugVL(cnt_e);

        if(cnt_v != cnt_e){
            OK = false;
            break;
        }
    }

    cout << (OK ? "Yes" : "No") << '\n';
}