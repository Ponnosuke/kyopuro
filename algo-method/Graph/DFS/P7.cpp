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

const vector<int> dh = {0, 1, 0, -1};
const vector<int> dw = {1, 0, -1, 0};
int H, W;

void dfs(pair<int, int> v, vector<string> &S, vector<vector<bool>> &seen){
    int vh = v.first, vw = v.second;
    seen.at(vh).at(vw) = true;

    // debug(vh);
    // debugL(vw);
    for(int i = 0; i < 4; i++){
        int nvh = vh + dh.at(i), nvw = vw + dw.at(i);
        // debug(nvh);
        // debugL(nvw);
        if(nvh < 0 || H <= nvh || nvw < 0 || W <= nvw){
            continue;
        }
        if(S.at(nvh).at(nvw) != '#'){
            continue;
        }
        if(seen.at(nvh).at(nvw)){
            continue;
        }

        // debug(nvh);
        // debugL(nvw);
        dfs(make_pair(nvh, nvw), S, seen);
    }

    return;
}

int main() {
    cin >> H >> W;
    vector<string> S(H);
    for(int i = 0; i < H; i++){
        cin >> S.at(i);
    }

    vector<vector<bool>> seen(H, vector<bool>(W, false));
    int ans = 0;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(seen.at(i).at(j)){
                continue;
            }
            if(S.at(i).at(j) == '#'){
                debug(i);
                debugL(j);
                dfs(make_pair(i, j), S, seen);
                ans++;
            }
            // else{
            //     seen.at(i).at(j) = true;
            // }
        }
    }

    cout << ans << '\n';

    return 0;
}