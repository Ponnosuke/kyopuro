#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << X << " "
    #define debugV(X) std::cerr << #X << " = " << X << ", "
    #define debugVL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugWL(Z) std::cerr << #Z << '\n'
#else
    #define debug(X)
    #define debugV(X)
    #define debugVL(Y)
    #define debugWL(Z)
#endif

vector<int> dh = {0,-1, 0, 1, 0};
vector<int> dw = {0, 0, 1, 0, -1};

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> field(H, vector<int>(W, 0));  // 0 := whilte, 1 := black
    int sum = 0;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            char ch;
            cin >> ch;
            if(ch == '#'){
                field.at(i).at(j) = 1;
                sum++;
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
                int nh = p + dh.at(i), nw = q + dw.at(i);
                if(0 <= nh && nh < H && 0 <= nw && nw < W){
                    sum -= field.at(nh).at(nw);
                    field.at(nh).at(nw) = 1 - field.at(nh).at(nw);
                    sum += field.at(nh).at(nw);
                }
            }
        }
        if(type == 1){
            cout << sum << '\n';
        }
    }
}