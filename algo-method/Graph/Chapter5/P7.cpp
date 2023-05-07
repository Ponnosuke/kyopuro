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
    vector<int> deg(N, 0);
    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        G.at(b).emplace_back(a);
        deg.at(a)++;
    }

    queue<int> Q;
    for(int i = 0; i < N; i++){
        sort(G.at(i).begin(), G.at(i).end());
        if(deg.at(i) == 0){
            Q.emplace(i);
        }
    }

    debugP(G);
    for(int i = 0; i < N; i++){
        debugL(i);
        for(int ele : G.at(i)){
            debug(ele);
        }
        debugP();
    }

    debugP(deg);
    for(int i = 0; i < N; i++){
        debug(i);
        debugL(deg.at(i));
    }

    deque<int> ans;
    while(!Q.empty()){
        int v = Q.front();
        Q.pop();
        ans.emplace_front(v);
        debugL(v);
        for(int nv : G.at(v)){
            deg.at(nv)--;
            debug(nv);
            debugL(deg.at(nv));
            if(deg.at(nv) == 0){
                debugL(nv);
                Q.emplace(nv);
            }
        }
    }

    int size = ans.size();
    debugL(size);
    for(int i = 0; i < size; i++){
        cout << ans.at(i);
        if(i < size - 1){
            cout << " ";
        }
    }
    cout << '\n';

    return 0;
}