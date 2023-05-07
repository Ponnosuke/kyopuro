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
    vector<vector<char>> A(H, vector<char>(W)), B(H, vector<char>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> A.at(i).at(j);
        }
    }
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> B.at(i).at(j);
        }
    }


    bool OK = false;
    for(int s = 0; s < H; s++){

        for(int j = 0; j < W; j++){
            char ini = A.at(0).at(j);
            for(int i = 0; i < H-1; i++){
                A.at(i).at(j) = A.at(i+1).at(j);
            }
            A.at(H-1).at(j) = ini;
        }

        for(int t = 0; t < W; t++){

            for(int i = 0; i < H; i++){
                char ini = A.at(i).at(0);
                for(int j = 0; j < W-1; j++){
                    A.at(i).at(j) = A.at(i).at(j+1);
                }
                A.at(i).at(W-1) = ini;
            }
            if(A == B){
                OK = true;
                break;
            }

        }

        if(OK){
            break;
        }
    }

    cout << (OK ? "Yes" : "No") << endl;

    return 0;
}