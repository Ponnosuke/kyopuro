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

vector<int> dH = {0, -1, 0, 1, 0};
vector<int> dW = {0, 0, 1, 0, -1};

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> field(H, vector<int>(W, 0));  // 1 := Black, 0 := White
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            char ch;
            cin >> ch;
            if(ch == '#'){
                field.at(i).at(j) = 1;
            }
        }
    }

    int Q;
    cin >> Q;
    while(Q--){
        int type;
        cin >> type;

        if(type == 0){
            int p, q;
            cin >> p >> q;

            for(int i = 0; i < 5; i++){
                int nh = p + dH.at(i), nw = q + dW.at(i);
                if(0 <= nh && nh < H && 0 <= nw && nw < W){
                    field.at(nh).at(nw) = 1 - field.at(nh).at(nw);
                }
            }
        }
        else{
            int p, q;
            cin >> p >> q;

            int cnt = 0;
            for(int i = 0; i < 5; i++){
                int nh = p + dH.at(i), nw = q + dW.at(i);
                if(0 <= nh && nh < H && 0 <= nw && nw < W){
                    cnt += field.at(nh).at(nw);
                }
            }

            cout << cnt << '\n';
        }
    }
}