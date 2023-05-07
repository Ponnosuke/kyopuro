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

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    vector<int> indeg(N, 0);
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        G.at(a).push_back(b);
        indeg.at(b)++;
    }

    queue<int> Q;
    for(int i = 0; i < N; i++){
        if(indeg.at(i) == 0){
            Q.push(i);
        }
    }

    vector<int> order;
    while(!Q.empty()){
        int v = Q.front();
        Q.pop();
        order.push_back(v);
        for(int nv : G.at(v)){
            indeg.at(nv)--;
            if(indeg.at(nv) == 0){
                Q.push(nv);
            }
        }
    }

    if(order.size() == N){
        cout << "No" << '\n';
    }
    else{
        cout << "Yes" << '\n';
    }
}