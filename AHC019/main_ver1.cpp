/*
    ver1

    立方体をひたすら敷き詰める
*/

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

int ret_b_index(int D, int x, int y, int z){
    return x * D * D + y * D + z;
}

void print_output(int D, int ret_n, vector<vector<i64>> &b){
    int b_size = D*D*D;

    cout << ret_n << '\n';
    for(int i = 0; i < b_size; i++){
        cout << b.at(0).at(i);

        if(i < b_size - 1){
            cout << " ";
        }
    }
    cout << '\n';
    for(int i = 0; i < b_size; i++){
        cout << b.at(1).at(i);

        if(i < b_size - 1){
            cout << " ";
        }
    }
    cout << '\n';

    return;
}

int main() {
    // input
    i64 D;
    cin >> D;
    vector<vector<vector<char>>> f(2, vector<vector<char>>(D, vector<char>(D, 0)));
    vector<vector<vector<char>>> r(2, vector<vector<char>>(D, vector<char>(D, 0)));
    for(int i = 0; i < D; i++){
        for(int j = 0; j < D; j++){
            cin >> f.at(0).at(i).at(j);
        }
    }
    for(int i = 0; i < D; i++){
        for(int j = 0; j < D; j++){
            cin >> r.at(0).at(i).at(j);
        }
    }
    for(int i = 0; i < D; i++){
        for(int j = 0; j < D; j++){
            cin >> f.at(1).at(i).at(j);
        }
    }
    for(int i = 0; i < D; i++){
        for(int j = 0; j < D; j++){
            cin >> r.at(1).at(i).at(j);
        }
    }

    vector<vector<i64>> b(2, vector<i64>(D*D*D, 0));
    vector<i64> n(2, 0);
    for(int i = 0; i < 2; i++){
        for(int x = 0; x < D; x++){
            for(int y = 0; y < D; y++){
                for(int z = 0; z < D; z++){
                    if(f.at(i).at(z).at(x) == '1' && r.at(i).at(z).at(y) == '1'){
                        n.at(i) += 1;
                        b.at(i).at(ret_b_index(D, x, y, z)) = n.at(i);
                    }
                }
            }
        }
    }

    int ret_n = max(n.at(0), n.at(1));
    print_output(D, ret_n, b);
}