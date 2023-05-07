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
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);  // X -> Y
    vector<int> indeg(N, 0);
    for(int i = 0; i < M; i++){
        int X, Y;
        cin >> X >> Y;
        X--;
        Y--;

        G[X].push_back(Y);
        indeg[Y]++;
    }

    queue<int> Q;
    for(int i = 0; i < N; i++){
        if(indeg[i] == 0){
            Q.push(i);
        }
    }

    bool OK = true;
    vector<int> ans(N);
    int num = 1;

    while(!Q.empty()){
        if((int)Q.size() != 1){
            OK = false;
            break;
        }

        int v = Q.front();
        Q.pop();

        ans[v] = num;
        num++;

        for(int nv : G[v]){
            indeg[nv]--;
            if(indeg[nv] == 0){
                Q.push(nv);
            }
        }
    }

    cout << (OK ? "Yes" : "No") << '\n';

    if(OK){
        for(int i = 0; i < N; i++){
            cout << ans[i];

            if(i < N-1){
                cout << " ";
            }
        }
        cout << '\n';
    }

    return 0;
}