#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << X << " "
    #define debugV(X) std::cerr << #X << " = " << X << ", "
    #define debugVL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugWL(Z) std::cerr << #Z << '\n'
#else
    #define debug(X)
    #define debugV(X)
    #define debugVL(Y)
    #define debugWL(Z)
#endif

int main() {
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    for(int i = 0; i < N-1; i++){
        debugVL(i);

        int A, B;
        cin >> A >> B;
        A--;
        B--;
        G.at(A).push_back(B);
        G.at(B).push_back(A);
    }

    debugWL(point32);

    int root = 0;
    queue<int> Q;
    vector<vector<int>> children(N);
    vector<int> parent(N, -1);
    vector<bool> seen(N, false);
    Q.push(root);
    seen.at(root) = true;
    vector<int> deg(N, 0); // deg[i] := i の子頂点の数
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
            deg.at(v)++;
        }
    }

    debugWL(point58);

    queue<int> leaf;
    for(int i = 0; i < N; i++){
        if(deg.at(i) == 0){
            leaf.push(i);
        }
    }

    debugWL(point67);

    vector<bool> isChosen(N, false);
    int cnt = 0;
    while(!leaf.empty()){
        int v = leaf.front();
        leaf.pop();

        bool flag = false;
        for(int nv : children.at(v)){
            flag |= isChosen.at(nv);

        }

        isChosen.at(v) = !flag;
        if(!flag){
            cnt++;
            if(cnt >= (N/2)){
                break;
            }
        }
        int p = parent.at(v);
        if(p == -1){
            continue;
        }
        deg.at(p)--;
        if(deg.at(p) == 0){
            leaf.push(p);
        }
    }

    debugWL(91);

    vector<int> ans;
    for(int i = 0; i < N; i++){
        if(isChosen.at(i)){
            ans.push_back(i);
        }
    }
    int Asize = ans.size();
    for(int i = 0; i < Asize; i++){
        cout << ans.at(i) + 1;
        if(i < Asize - 1){
            cout << " ";
        }
    }
    cout << '\n';

    return 0;
}