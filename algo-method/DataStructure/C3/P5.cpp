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

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for(int i = 0; i < H; i++){
        cin >> S.at(i);
    }
    vector<vector<int>> field(H+2, vector<int>(W+2, 0));
    for(int i = 1; i < H+1; i++){
        for(int j = 1; j < W+1; j++){
            // debug(i);
            // debugL(j);
            if(S.at(i-1).at(j-1) == '#'){
                field.at(i).at(j) = 1;
            }
        }
    }

    // debugP(pointA);

    int Q;
    cin >> Q;
    while(Q--){
        int x, y;
        cin >> x >> y;
        x++;
        y++;

        debugP(pointB);

        int cnt = 0;
        debug(x);
        debugL(y);
        debugL(field.at(0).size());
        debugL(field.size());
        cnt += (field.at(x-1).at(y) + field.at(x).at(y+1) + field.at(x+1).at(y) + field.at(x).at(y-1));
        cout << cnt << '\n';
    }
}