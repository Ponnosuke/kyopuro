#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << #X << " = " << X << ", "
    #define debugL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugP(Z) std::cerr << #Z << '\n'
#else
    #define debug(X)
    #define debugL(Y)
    #define debugP(Z)
#endif

vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for(int i = 0; i < H; i++){
        cin >> S.at(i);
    }

    debugP(pointA);

    int Q;
    cin >> Q;
    while(Q--){
        int x, y;
        cin >> x >> y;

        debugP(pointB);
        debug(x);
        debugL(y);

        int cnt = 0;
        for(int i = 0; i < 4; i++){
            int nx = x + dx.at(i), ny = y + dy.at(i);
            
            if(0 <= nx && nx < H && 0 <= ny && ny < W){
                if(S.at(nx).at(ny) == '#'){
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }
}