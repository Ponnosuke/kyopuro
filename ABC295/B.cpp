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
    i64 R, C;
    cin >> R >> C;
    vector<vector<char>> B(R, vector<char>(C));
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> B.at(i).at(j);
        }
    }
    // vector<vector<char>> field = B;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            char nowCh = B.at(i).at(j);
            if('1' <= nowCh && nowCh <= '9'){
                for(int k = 0; k < R; k++){
                    for(int l = 0; l < C; l++){
                        if('1' <= B.at(k).at(l) && B.at(k).at(l) <= '9'){
                            continue;
                        }

                        i64 nowNum = (i64)(nowCh - '0');
                        i64 dist = abs(i - k) + abs(j - l);
                        if(dist <= nowNum){
                            B.at(k).at(l) = '.';
                        }
                    }
                }

                B.at(i).at(j) = '.';
            }
        }
    }

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cout << B.at(i).at(j);
        }
        cout << '\n';
    }
}