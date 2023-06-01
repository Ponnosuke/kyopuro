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
    for(int i = 0; i < N-1; i++){
        int a, b;
        cin >> a >> b;
        G.at(a).push_back(b);
        G.at(b).push_back(a);
    }

    vector<vector<int>> children(N);
    vector<int> parent(N, 0);
    queue<int> Que;
    Que.push(0);
    vector<bool> visited(N, false);
    visited.at(0) = true;
    while(!Que.empty()){
        int v = Que.front();
        Que.pop();

        debugVL(v);

        for(int nv : G.at(v)){
            if(visited.at(nv)){
                continue;
            }

            parent.at(nv) = v;
            children.at(v).push_back(nv);
            visited.at(nv) = true;
            Que.push(nv);
        }
    }

    for(int i = 0; i < N; i++){
        sort(children.at(i).begin(), children.at(i).end());
    }

    // debug
    // for(int i = 0; i < N; i++){
    //     debugVL(i);
    //     for(int j = 0; j < children.at(i).size(); j++){
    //         debug(children.at(i).at(j));
    //     }
    //     debugWL();
    // }
    // debugWL();

    int Q;
    cin >> Q;
    debugVL(Q);
    while(Q--){
        int v;
        cin >> v;
        int P = parent.at(v);
        int cSize = children.at(P).size();
        for(int i = 0; i < cSize; i++){
            cout << children.at(P).at(i);

            if(i < cSize - 1){
                cout << " ";
            }
        }
        cout << '\n';
    }

    return 0;
}