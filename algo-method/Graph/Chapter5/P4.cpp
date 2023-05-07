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

void dfs(int v, vector<vector<int>> &G, vector<char> &field, vector<bool> &seen,char color){
    for(int nv : G.at(v)){
        if(seen.at(nv)){
            continue;
        }

        if(color == 'b'){
            field.at(nv) = 'w';
            seen.at(nv) = true;
            dfs(nv, G, field, seen, 'w');
        }
        else{
            field.at(nv) = 'b';
            seen.at(nv) = true;
            dfs(nv, G, field, seen, 'b');
        }
    }

    return;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        G.at(a).emplace_back(b);
        G.at(b).emplace_back(a);
    }

    vector<char> field(N, 'n');
    vector<bool> seen(N, false);
    field.at(0) = 'b';

    for(int i = 0; i < N; i++){
        if(!seen.at(i)){
            seen.at(i) = true;
            field.at(i) = 'b';
            dfs(i, G, field, seen, 'b');
        }
    }

    bool OK = true;
    for(int i = 0; i < N; i++){
        for(int j : G.at(i)){
            debug(i);
            debugL(j);
            debug(field.at(i));
            debugL(field.at(j));
            if(field.at(i) == field.at(j)){
                OK = false;
            }
            debugP();
        }
        if(!OK){
            break;
        }
    }

    cout << (OK ? "Yes" : "No") << '\n';
}