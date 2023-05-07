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

vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};

struct Point{
    int y;
    int x;

    Point(int iy, int ix): y(iy), x(ix) {
    }

    Point(){
    }

    void Set(int iy, int ix){
        y = iy;
        x = ix;
        return;
    }
};

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    int xs = -1, ys = -1, xg = -1, yg = -1; 
    for(int i = 0; i < H; i++){
        cin >> S.at(i);

        for(int j = 0; j < W; j++){
            if(S.at(i).at(j) == 'S'){
                xs = j;
                ys = i;
            }
            if(S.at(i).at(j) == 'G'){
                xg = j;
                yg = i;
            }
        }
    }

    vector<vector<int>> dist(H, vector<int>(W, -1));
    queue<Point> Q;
    Q.emplace(ys, xs);  // emplace だとこの入力でコンストラクタを呼び出してくれるらしい
    dist.at(ys).at(xs) = 0;
    while(!Q.empty()){
        Point v = Q.front();
        int x = v.x, y = v.y;
        Q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx.at(i), ny = y + dy.at(i);
            if(ny < 0 || H <= ny || nx < 0 || W <= nx){
                continue;
            }
            if(dist.at(ny).at(nx) != -1){
                continue;
            }
            if(S.at(ny).at(nx) == '#'){
                continue;
            }

            dist.at(ny).at(nx) = dist.at(y).at(x) + 1;
            Q.emplace(ny, nx); // ここでもこの入力でコンストラクタを呼び出してくれている
        }
    }

    debugWL(debug);
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            debug(dist.at(i).at(j));
        }
        debugWL();
    }
    debugWL();

    cout << dist.at(yg).at(xg) << endl;

    return 0;
}