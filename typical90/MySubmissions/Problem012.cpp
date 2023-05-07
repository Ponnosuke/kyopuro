#include <bits/stdc++.h>
#include <atcoder/dsu>
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

vector<int> dh = {-1, 0, 1, 0};
vector<int> dw = {0, 1, 0, -1};

int getIndex(int r, int c, int W){
    return W*r + c;
}

int main() {
    int H, W;
    cin >> H >> W;
    atcoder::dsu uf(H*W);

    int Q;
    cin >> Q;

    vector<vector<int>> field(H, vector<int>(W, 0));  // 0 := White, 1 := Red

    debugWL(pointA);

    while(Q--){
        int t;
        cin >> t;

        if(t == 1){
            debugWL(routeA);

            int r, c;
            cin >> r >> c;
            r--;
            c--;

            field.at(r).at(c) = 1;
            for(int i = 0; i < 4; i++){
                int nr = r + dh.at(i), nc = c + dw.at(i);
                if(0 <= nr && nr < H && 0 <= nc && nc < W){
                    if(field.at(nr).at(nc) == 1){
                        int index1 = getIndex(r, c, W);
                        int index2 = getIndex(nr, nc, W);
                        debugV(index1);
                        debugVL(index2);
                        uf.merge(index1, index2);
                    }
                }
            }
            debugWL();
        }
        if(t == 2){
            debugWL(routeB);

            int ra, ca, rb, cb;
            cin >> ra >> ca >> rb >> cb;
            ra--;
            ca--;
            rb--;
            cb--;

            int index1 = getIndex(ra, ca, W);
            int index2 = getIndex(rb, cb, W);
            debugV(index1);
            debugVL(index2);
            if(field.at(ra).at(ca) == 1 && field.at(rb).at(cb) == 1 && uf.same(index1, index2)){
                cout << "Yes" << '\n';
            }
            else{
                cout << "No" << '\n';
            }

            debugWL();
        }
    }
}