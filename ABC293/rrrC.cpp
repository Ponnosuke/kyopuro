/*
    C - Make Takahashi Happy https://atcoder.jp/contests/abc293/tasks/abc293_c 

    本番で出した DFS でやる方法をちょっと最適化したもの
    具体的には、visited がいらないことに気づいて (進む方向的に一度訪れている頂点をもう一回探索
    しようとすることがないから) それを取り除いた。ただ、あっても問題ないから本番時に心配なら書い
    とくといいかも (ただ本番ではこの vitited の管理をミスってるの気づけず WA を 2回出してしまっ
    たが……)

    計算量は bit全探索するより こっち (DFS) の方が軽そう
*/

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

void dfs(i64 vx, i64 vy, set<i64> &path, i64 H, i64 W, i64 &cnt, vector<vector<i64>> &A){
    if(path.count(A.at(vy).at(vx))){
        return;
    }
    if(vx == W-1 && vy == H-1){
        cnt++;
        return;
    }

    path.insert(A.at(vy).at(vx));

    for(i64 i = 0; i < 2; i++){
        i64 nvx = vx + dw.at(i), nvy = vy + dh.at(i);

        if(nvx < 0 || W <= nvx || nvy < 0 || H <= nvy){
            continue;
        }

        dfs(nvx, nvy, path, H, W, cnt, A);
    }

    path.erase(A.at(vy).at(vx));

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
    set<i64> path;
    dfs(0, 0, path, H, W, cnt, A);

    cout << cnt << endl;
}