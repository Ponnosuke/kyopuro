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
    i64 N, D;
    cin >> N >> D;
    vector<i64> X(N), Y(N);
    for(int i = 0; i < N; i++){
        cin >> X.at(i) >> Y.at(i);
    }

    vector<vector<int>> G(N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            double dist = hypot((double)X.at(i) - (double)X.at(j), (double)Y.at(i) - (double)Y.at(j));

            if(dist <= D){
                G.at(i).push_back(j);
                G.at(j).push_back(i);
            }
        }
    }

    vector<bool> visited(N, false);
    visited.at(0) = true;
    queue<int> Q;
    Q.push(0);
    while(!Q.empty()){
        int v = Q.front();
        Q.pop();

        for(int nv : G.at(v)){
            if(visited.at(nv)){
                continue;
            }

            Q.push(nv);
            visited.at(nv) = true;
        }
    }

    for(int i = 0; i < N; i++){
        if(visited.at(i)){
            cout << "Yes" << '\n';
        }
        else{
            cout << "No" << '\n';
        }
    }
}