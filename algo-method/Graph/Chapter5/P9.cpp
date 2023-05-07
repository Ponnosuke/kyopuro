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
    vector<vector<int>> G(N);
    vector<int> deg(N, 0);
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        G.at(b).emplace_back(a);
        deg.at(a)++;
    }

    queue<int> Q;
    for(int i = 0; i < N; i++){
        if(deg.at(i) == 0){
            Q.emplace(i);
        }
    }

    set<int> sinks;
    while(!Q.empty()){
        int v = Q.front();
        Q.pop();
        sinks.insert(v);
        for(int nv : G.at(v)){
            deg.at(nv)--;
            if(deg.at(nv) == 0){
                Q.emplace(nv);
            }
        }
    }

    bool isLoop = false;
    for(int i = 0; i < N; i++){
        if(!sinks.count(i)){
            isLoop = true;
            break;
        }
    }

    cout << (isLoop ? "Yes" : "No") << endl;
}