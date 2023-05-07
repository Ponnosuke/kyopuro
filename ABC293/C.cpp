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

vector<i64> dh = {1, 0};
vector<i64> dw = {0, 1};

void dfs(i64 vx, i64 vy, vector<vector<bool>> &visited, set<i64> &path, i64 H, i64 W, i64 &cnt, vector<vector<i64>> &A){
    visited.at(vy).at(vx) = true;

    debugV(vy);
    debugVL(vx);

    if(path.count(A.at(vy).at(vx))){
        debugWL(OUT);
        debugVL(A.at(vy).at(vx));

        visited.at(vy).at(vx) = false;
        return;
    }
    if(vx == W-1 && vy == H-1){
        cnt++;
        visited.at(vy).at(vx) = false;
        return;
    }

    path.insert(A.at(vy).at(vx));

    debugP();


    debugP();

    for(i64 i = 0; i < 2; i++){
        i64 nvx = vx + dw.at(i), nvy = vy + dh.at(i);

        if(nvx < 0 || W <= nvx || nvy < 0 || H <= nvy){
            continue;
        }

        debugP();

        if(visited.at(nvy).at(nvx)){
            continue;
        }

        debugV(nvy);
        debugVL(nvx);
        dfs(nvx, nvy, visited, path, H, W, cnt, A);
    }

    visited.at(vy).at(vx) = false;
    path.erase(A.at(vy).at(vx));
    debugWL();

    return;
}

int main() {
    i64 H, W;
    cin >> H >> W;
    vector<vector<i64>> A(H, vector<i64>(W));
    for(i64 i = 0; i < H; i++){
        for(i64 j = 0; j < W; j++){
            cin >> A.at(i).at(j);
        }
    }

    i64 cnt = 0;
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    set<i64> path;
    dfs(0, 0, visited, path, H, W, cnt, A);

    cout << cnt << endl;
}