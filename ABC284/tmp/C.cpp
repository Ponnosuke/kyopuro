#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << #X << " = " << X << ", "
    #define debugL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugP(Z) std::cerr << #Z << '\n'
#else
    #define debug(X) 3389
    #define debugL(Y) 3390
    #define debugP(Z) 3391
#endif

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> u(M), v(M);
    for(int i = 0; i < M; i++){
        cin >> u.at(i) >> v.at(i);
    }

    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++){
        int tmpU = u.at(i), tmpV = v.at(i);
        tmpU--;
        tmpV--;
        G.at(tmpU).emplace_back(tmpV);
        G.at(tmpV).emplace_back(tmpU);
    }

    queue<int> Q;
    vector<bool> seen(N, false);
    i64 ans = 0;
    for(int i = 0; i < N; i++){
        if(seen.at(i)){
           continue; 
        }
        
        ans++;
        Q.emplace(i);
        seen.at(i) = true;
        while(!Q.empty()){
            int ver = Q.front();
            Q.pop();
            for(int nv : G.at(ver)){
                if(seen.at(nv)){
                    continue;
                }

                seen.at(nv) = true;
                Q.emplace(nv);
            }
        }
    }

    cout << ans << '\n';
}