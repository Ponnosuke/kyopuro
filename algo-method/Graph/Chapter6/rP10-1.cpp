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
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    for(int i = 0; i < N-1; i++){
        int a, b;
        cin >> a >> b;

        G.at(a).push_back(b);
        G.at(b).push_back(a);
    }

    vector<vector<int>> children(N);
    vector<int> parent(N, -1);
    vector<int> deg(N, 0);  // 子頂点の数
    queue<int> Q;
    vector<bool> seen(N, false);
    int root = 0;
    Q.push(root);
    seen.at(root) = true;
    while(!Q.empty()){
        int v = Q.front();
        Q.pop();
        for(int nv : G.at(v)){
            if(seen.at(nv)){
                continue;
            }

            children.at(v).push_back(nv);
            deg.at(v)++;
            parent.at(nv) = v;
            seen.at(v) = true;
            Q.push(nv);
        }
    }

    for(int i = 0; i < N; i++){
        if(deg.at(i) == 0){
            Q.push(i);
        }
    }

    vector<bool> isChosen(N, false);
    int ans = 0;
    while(!Q.empty()){
        int v = Q.front();
        Q.pop();
        int p = parent.at(v);

        if(!isChosen.at(v)){
            isChosen.at(v) = true;
            if(p != -1){
                isChosen.at(p) = true;
            }
            ans++;
        }

        if(p == -1){
            continue;
        }
        deg.at(p)--;
        if(deg.at(p) == 0){
            Q.push(p);
        }
    }

    cout << ans << endl;
}