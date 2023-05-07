#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << X << " "
    #define debugV(X) std::cerr << #X << " = " << X << ", "
    #define debugVL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugW(Z) std::cerr << #Z << '\n'
#else
    #define debug(X)
    #define debugV(X)
    #define debugVL(Y)
    #define debugW(Z)
#endif

// NlogN ≒ 10^5 * 10 = 10^6
int main() {
    int N;
    cin >> N;
    map<string, string> G;
    map<string, int> indeg;
    // O(NlogN)
    for(int i = 0; i < N; i++){
        string S, T;
        cin >> S >> T;
        G[S] = T;
        indeg[T]++;
        if(!indeg.count(S)){
            indeg[S] = 0;
        }
    }

    queue<string> Q;
    for(auto [p, q] : indeg){
        if(q == 0){
            Q.push(p);
        }

        debugV(p);
        debugVL(q);
    }

    int cnt = 0;
    // O(NlogN)
    while(!Q.empty()){
        string v = Q.front();
        debugVL(v);
        Q.pop();
        cnt++;

        if(!G.count(v)){
            continue;
        }
        string nv = G.at(v);
        indeg.at(nv)--;
        if(indeg.at(nv) == 0){
            Q.push(nv);
        }
    }

    if(cnt == indeg.size()){
        cout << "Yes" << '\n';
    }
    else{
        cout << "No" << '\n';
    }
}