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

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> field(H, vector<int>(W, 0)); // 0 := white, 1 := black
    vector<int> rCnt(H, 0), cCnt(W, 0);
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            char ch;
            cin >> ch;
            if(ch == '#'){
                field.at(i).at(j) = 1;
                rCnt.at(i)++;
                cCnt.at(j)++;
            }
        }
    }

    int Q;
    cin >> Q;
    while(Q--){
        int p, q;
        cin >> p >> q;
        int ans = rCnt.at(p) + cCnt.at(q) - field.at(p).at(q);

        cout << ans << '\n';
    }

    return 0;
}