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

    debugP(point28);

    vector<vector<int>> children(N);
    vector<int> parent(N, -1);
    int root = 0;
    queue<int> Q;
    vector<bool> seen(N, false);
    Q.push(root);
    parent.at(root) = root;
    seen.at(root) = true;
    while(!Q.empty()){
        int v = Q.front();
        Q.pop();
        for(int nv : G.at(v)){
            if(seen.at(nv)){
                continue;
            }

            children.at(v).push_back(nv);
            parent.at(nv) = v;
            seen.at(nv) = true;
            Q.push(nv);
        }
    }

    debugP(point51);

    vector<bool> isChosen(N, false);
    queue<int> leaf;
    vector<int> deg(N, 0);  // deg.at(v)  v の子への辺の数
    for(int i = 0; i < N; i++){
        deg.at(i) = (int)children.at(i).size();

        if(deg.at(i) == 0){
            leaf.push(i);
        }
    }
    while(!leaf.empty()){
        int v = leaf.front();
        leaf.pop();
        bool flag = false;
        for(int nv : children.at(v)){
            flag |= isChosen.at(nv);
        }

        isChosen.at(v) = !flag;

        int par = parent.at(v);
        deg.at(par)--;
        if(deg.at(par) == 0){
            leaf.push(par);
        }
    }

    int ans = 0;
    for(int i = 0; i < N; i++){
        if(isChosen.at(i)){
            ans++;
        }
    }

    cout << ans << endl;
}