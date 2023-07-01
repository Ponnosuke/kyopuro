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

const string TARGET_STR = "snuke";

vector<int> di = {-1, 0, 1, 0};
vector<int> dj = {0, 1, 0, -1};

void dfs(int i, int j, vector<string> &S, vector<vector<bool>> &visited, bool &OK, int H, int W){
    if(OK){
        return;
    }

    if((i == (H-1)) && (j == (W-1))){
        OK = true;
        return;
    }

    char now_char = S.at(i).at(j);

    visited.at(i).at(j) = true;

    for(int d = 0; d < 4; d++){
        int ni = i + di.at(d), nj = j + dj.at(d);
        if(ni < 0 || H <= ni || nj < 0 || W <= nj){
            continue;
        }
        if(visited.at(ni).at(nj)){
            continue;
        }

        int now_char_idx = 0;
        for(int idx = 0; idx < 5; idx++){
            if(now_char == TARGET_STR.at(idx)){
                now_char_idx = idx;
            }
        }

        int next_char_idx = (now_char_idx + 1) % 5;
        if(S.at(ni).at(nj) == TARGET_STR.at(next_char_idx)){
            dfs(ni, nj, S, visited, OK, H, W);
        }
    }

    visited.at(i).at(j) = false;

    return;
}

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for(int i = 0; i < H; i++){
        cin >> S.at(i);
    }

    debugP();

    vector<vector<bool>> dp(H, vector<bool>(W, false));
    if(S.at(0).at(0) != 's'){
        cout << "No" << endl;

        return 0;
    }

    debugP();

    dp.at(0).at(0) = true;
    bool OK = false;
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    visited.at(0).at(0) = true;
    dfs(0, 0, S, visited, OK, H, W);

    cout << (OK ? "Yes" : "No") << '\n';
}