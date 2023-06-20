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

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> B(W, vector<int>(H, 0));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> B.at(j).at(i);
        }
    }

    for(int i = 0; i < W; i++){
        for(int j = 0; j < H; j++){
            cout << B.at(i).at(j);

            if(j < H-1){
                cout << " ";
            }
        }
        cout << '\n';
    }

    return 0;
}