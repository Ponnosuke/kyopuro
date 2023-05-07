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

enum{
    BLACK,
    WHITE,
};

void dfs(int v, vector<vector<int>> &G, vector<int> &field, int color){
    field.at(v) = color;
    for(int nv : G.at(v)){
        if(field.at(nv) != -1){
            continue;
        }

        if(color == BLACK){
            dfs(nv, G, field, WHITE);
        }
        else{
            dfs(nv, G, field, BLACK);
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

    vector<int> field(N, -1);

    for(int i = 0; i < N; i++){
        if(field.at(i) == -1){
            dfs(i, G, field, BLACK);
        }
    }

    bool OK = true;
    for(int i = 0; i < N; i++){
        for(int j : G.at(i)){
            if(field.at(i) == field.at(j)){
                OK = false;
            }
        }
        if(!OK){
            break;
        }
    }

    cout << (OK ? "Yes" : "No") << '\n';
}