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
    int N;
    cin >> N;
    map<string, int> index;
    vector<vector<int>> G(2*N);
    int cnt = 0;
    vector<int> indeg(2*N, 0);
    for(int i = 0; i < N; i++){
        string S, T;
        cin >> S >> T;

        if(!index.count(S)){
            index[S] = cnt;
            cnt++;
        }
        if(!index.count(T)){
            index[T] = cnt;
            cnt++;
        }

        int idxS = index.at(S), idxT = index.at(T);
        G.at(idxS).push_back(idxT);
        indeg.at(idxT)++;
    }

    queue<int> Q;
    for(int i = 0; i < cnt; i++){
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

    if(cnt == (int)order.size()){
        cout << "Yes" << '\n';
    }
    else{
        cout << "No" << '\n';
    }
}