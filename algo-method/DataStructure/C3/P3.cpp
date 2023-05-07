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
    int H, W, x, y;
    cin >> H >> W >> x >> y;
    vector<string> S(H);
    for(int i = 0; i < H; i++){
        cin >> S.at(i);
    }

    for(int i = x-1; i <= x+1; i++){
        for(int j = y-1; j <= y+1; j++){
            cout << S.at(i).at(j);
        }
        cout << '\n';
    }
}