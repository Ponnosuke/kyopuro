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
    i64 N, Q;
    cin >> N >> Q;

    vector<i64> dig(N, 0);
    int renketu = 0;
    vector<set<i64>> comb(N);
    while(Q--){
        int type;
        cin >> type;

        if(type == 1){
            int u, v;
            cin >> u >> v;
            u--;
            v--;

            dig.at(u)++;
            dig.at(v)++;

            if(dig.at(u) == 1){
                renketu++;
            }
            if(dig.at(v) == 1){
                renketu++;
            }

            comb[u].insert(v);
            comb[v].insert(u);
        }
        else{
            int v;
            cin >> v;
            v--;
            if(dig.at(v) != 0){
                dig.at(v) = 0;
                renketu--;
            }
            
            for(auto x : comb[v]){
                comb[x].erase(v);
                dig.at(x)--;
                if(dig.at(x) == 0){
                    renketu--;
                }
            }
            comb[v].clear();
        }

        cout << N - renketu << '\n';
    }

    return 0;
}