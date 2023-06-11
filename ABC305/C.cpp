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
    vector<vector<char>> S(H, vector<char>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
           cin >> S.at(i).at(j);
        }
    }

    int a = 1000, b = -1, c = 1000, d = -1;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(S.at(i).at(j) == '#'){
                a = min(a, i);
                b = max(b, i);
                c = min(c, j);
                d = max(d, j);
            }
        }
    }

    // int ans_i, ans_j;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(S.at(i).at(j) == '.'){
                if((a <= i) && (i <= b) && (c <= j) && (j <= d)){
                    cout << i + 1 << " " << j + 1 << endl;

                    return 0;
                }
            }
        }
    }

    return 0;
}