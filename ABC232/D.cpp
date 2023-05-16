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

const vector<int> dy = {0, 1};
const vector<int> dx = {1, 0};

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> C(H);
    for(int i = 0; i < H; i++){
        cin >> C.at(i);
    }

    vector<vector<i64>> dist(H, vector<i64>(W, -1));
    dist.at(0).at(0) = 1;
    queue<pair<int, int>> Q;
    Q.emplace(make_pair(0, 0));
    while(!Q.empty()){
        auto [y, x] = Q.front();
        Q.pop();

        for(int d = 0; d < 2; d++){
            int ny = y + dy.at(d), nx = x + dx.at(d);
            if(ny < 0 || H <= ny || nx < 0 || W <= nx){
                continue;
            }
            if(C.at(ny).at(nx) == '#'){
                continue;
            }
            if(dist.at(ny).at(nx) != -1){
                continue;
            }
            dist.at(ny).at(nx) = dist.at(y).at(x) + 1;
            Q.emplace(ny, nx);
        }
    }

    // debug
    debugWL(dist);
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            debug(dist.at(i).at(j));
        }
        debugWL();
    }
    debugWL();

    i64 ans = 1;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            ans = max(ans, dist.at(i).at(j));
        }
    }

    cout << ans << endl;

    return 0;
}