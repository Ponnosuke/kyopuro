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

    queue<int> Q;
    for(int i = 0; i < N; i++){
        if(dig.at(i) == 1){
            Q.push(i);
            break;
        }
    }

    vector<int> dist(N, -1);
    dist.at(Q.front()) = 0;
    vector<int> L;
    while(!Q.empty()){
        int v = Q.front();
        Q.pop();

        for(int nv : G.at(v)){
            if(dist.at(nv) != -1){
                continue;
            }

            dist.at(nv) = dist.at(v) + 1;
            Q.push(nv);

            if(dist.at(nv) % 3 == 1){
                L.push_back(dig.at(nv));
            }
        }
    }

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