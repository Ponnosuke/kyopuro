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

const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};

int main() {
    int H, W;
    cin >> H >> W;
    int X0, Y0, X1, Y1;
    cin >> X0 >> Y0 >> X1 >> Y1;
    vector<string> S(H);
    for(int i = 0; i < H; i++)  cin >> S.at(i);

    vector<vector<int>> dist(H, vector<int>(W, -1));
    queue<pair<int, int>> Q;
    dist.at(X0).at(Y0) = 0;
    Q.push(make_pair(X0, Y0));

    // debugP(point33);

    while(!Q.empty()){
        pair<int, int> now = Q.front();
        Q.pop();

        for(int i = 0; i < 4; i++){
            int nx = now.first + dx.at(i), ny = now.second + dy.at(i);
            if(nx < 0 || H <= nx || ny < 0 || W <= ny){
                continue;
            }
            if(dist.at(nx).at(ny) != -1){
                continue;
            }
            if(S.at(nx).at(ny) == 'B'){
                continue;
            }

            dist.at(nx).at(ny) = dist.at(now.first).at(now.second) + 1;
            Q.push(make_pair(nx, ny));

            debug(now.first); debugL(now.second);
            debugL(dist.at(now.first).at(now.second));
            debug(nx); debugL(ny);
            debugL(dist.at(nx).at(ny));
            debugP();
        }

        // debugP(point59);

    }

    // for(int i = 0; i < H; i++){
    //     for(int j = 0; j < W; j++){
    //         debug(i);
    //         debugL(j);
    //         debugL(dist.at(i).at(j));
    //     }
    //     debugP();
    // }

    cout << dist.at(X1).at(Y1) << '\n';
}