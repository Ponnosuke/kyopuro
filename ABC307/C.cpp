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
    int HA, WA;
    cin >> HA >> WA;
    vector<string> A(HA);
    int A_black_cnt = 0;
    int max_A_H = 0, max_A_W = 0;
    int min_A_H = HA - 1, min_A_W = WA - 1;
    for(int i = 0; i < HA; i++){
        cin >> A.at(i);
        for(int j = 0; j < WA; j++){
            if(A.at(i).at(j) == '#'){
                max_A_H = max(max_A_H, i);
                min_A_H = min(min_A_H, i);
                max_A_W = max(max_A_W, j);
                min_A_W = min(min_A_W, j);
                A_black_cnt++;
            }
        }
    }
    int HB, WB;
    cin >> HB >> WB;
    vector<string> B(HB);
    int B_black_cnt = 0;
    int max_B_H = 0, max_B_W = 0;
    int min_B_H = HB - 1, min_B_W = WB - 1;
    for(int i = 0; i < HB; i++){
        cin >> B.at(i);
        for(int j = 0; j < WB; j++){
            if(B.at(i).at(j) == '#'){
                max_B_H = max(max_B_H, i);
                min_B_H = min(min_B_H, i);
                max_B_W = max(max_B_W, j);
                min_B_W = min(min_B_W, j);
                B_black_cnt++;
            }
        }
    }
    int HX, WX;
    cin >> HX >> WX;
    vector<string> X(HX);
    int X_black_cnt = 0;
    int max_X_H = 0, max_X_W = 0;
    int min_X_H = HB - 1, min_X_W = WB - 1;
    for(int i = 0; i < HX; i++){
        cin >> X.at(i);
        for(int j = 0; j < WX; j++){
            if(X.at(i).at(j) == '#'){
                max_X_H = max(max_X_H, i);
                min_X_H = min(min_X_H, i);
                max_X_W = max(max_X_W, j);
                min_X_W = min(min_X_W, j);
                X_black_cnt++;
            }
        }
    }

    // debug
    debugV(A_black_cnt);
    debugV(B_black_cnt);
    debugVL(X_black_cnt);

    if(A_black_cnt + B_black_cnt < X_black_cnt){
        cout << "No" << '\n';
        
        return 0;
    }
    if(max(A_black_cnt, B_black_cnt) > X_black_cnt){
        cout << "No" << '\n';

        return 0;
    }

    int A_black_height = max_A_H - min_A_H + 1;
    int A_black_width = max_A_W - min_A_W + 1;
    int B_black_height = max_B_H - min_B_H + 1;
    int B_black_width = max_B_W - min_B_W + 1;
    int max_black_height = max(A_black_height, B_black_height) + 1;
    int max_black_width = max(A_black_width, B_black_width) + 1;
    int X_black_height = max_X_H - min_X_H + 1;
    int X_black_width = max_X_W - min_X_W + 1;

    debugV(max_black_height);
    debugVL(max_black_width);
    debugV(X_black_height);
    debugVL(X_black_width);

    if(max_black_height != X_black_height){
        cout << "No" << '\n';

        return 0;
    }
    if(max_black_width != X_black_width){
        cout << "No" << '\n';

        return 0;
    }



    int use_black_cnt = 0;
    bool can = false;
    int ini_ia = min_A_H, ini_ja = min_A_W;
    int ini_ib = min_B_H, ini_jb = min_B_W;
    vector<string> made_table(HX, "");
    for(int i = 0; i < HX; i++){
        string tmp = "";
        for(int j = 0; j < WX; j++){
            tmp += ".";
        }
        made_table.at(i) = tmp;
    }
    for(int ix = 0; ix < HX; ix++){
        for(int jx = 0; jx < WX; jx++){
            if(X.at(ix).at(jx) == '#'){
                bool A_can = true, B_can = true;
                // A を一番最初に合わせる
                if(ix + A_black_height - 1 < HX && jx + A_black_height - 1 < WX){
                    for(int i = 0; i < HX; i++){
                        string tmp = "";
                        for(int j = 0; j < WX; j++){
                            tmp += ".";
                        }
                        made_table.at(i) = tmp;
                    }
                    vector<string> rest_table = X;
                    for(int ia = 0; ia < A_black_height; ia++){
                        for(int ja = 0; ja < A_black_width; ja++){
                            if(A.at(ini_ia + ia).at(ini_ja + ja) == '#'){
                                if(X.at(ix + ia).at(jx + ja) != '#'){
                                    A_can = false;
                                    break;
                                }
                                else{
                                    made_table.at(ix + ia).at(jx + ja) = '#';
                                    rest_table.at(ix + ia).at(jx + ja) = '.';
                                }
                            }
                        }
                        if(!A_can){
                            break;
                        }
                    }
                    for(int imt = 0; imt < HX; imt++){
                        for(int jmt = 0; jmt < WX; jmt++){
                            if(rest_table.at(imt).at(jmt) == '#'){
                                for(int ib = 0; ib < B_black_height; ib++){
                                    for(int jb = 0; jb < B_black_width; jb++){
                                        if(ini_ib + ib >= HX || ini_jb + jb >= WX){
                                            A_can = false;
                                            break;
                                        }
                                        if(B.at(ini_ib + ib).at(ini_jb + jb) == '#'){
                                            if(rest_table.at(ix + ib).at(jx + jb) != '#'){
                                                A_can = false;
                                                break;
                                            }
                                            else{
                                                made_table.at(ix + ib).at(jx + jb) = '#';
                                                rest_table.at(ix + ib).at(jx + jb) = '.';
                                            }
                                        }
                                    }
                                    if(!A_can){
                                        break;
                                    }
                                }
                            }

                            if(!A_can){
                                break;
                            }
                        }

                        if(!A_can){
                            break;
                        }
                    }

                    if(made_table != X){
                        A_can = false;
                    }
                }
                else{
                    A_can = false;
                }

                // Bを最初に合わせる
                if(ix + B_black_height - 1 < HX && jx + B_black_height - 1 < WX){
                    for(int i = 0; i < HX; i++){
                        string tmp = "";
                        for(int j = 0; j < WX; j++){
                            tmp += ".";
                        }
                        made_table.at(i) = tmp;
                    }
                    vector<string> rest_table = X;
                    for(int ib = 0; ib < B_black_height; ib++){
                        for(int jb = 0; jb < B_black_width; jb++){
                            if(B.at(ini_ib + ib).at(ini_jb + jb) == '#'){
                                if(B.at(ix + ib).at(jx + jb) != '#'){
                                    B_can = false;
                                    break;
                                }
                                else{
                                    made_table.at(ix + ib).at(jx + jb) = '#';
                                    rest_table.at(ix + ib).at(jx + jb) = '.';
                                }
                            }
                        }
                        if(!B_can){
                            break;
                        }
                    }
                    for(int imt = 0; imt < HX; imt++){
                        for(int jmt = 0; jmt < WX; jmt++){
                            if(rest_table.at(imt).at(jmt) == '#'){
                                for(int ia = 0; ia < A_black_height; ia++){
                                    for(int ja = 0; ja < A_black_width; ja++){
                                        if(ini_ia + ia >= HX || ini_ja + ja >= WX){
                                            B_can = false;
                                            break;
                                        }
                                        if(A.at(ini_ia + ia).at(ini_ja + ja) == '#'){
                                            if(rest_table.at(ix + ia).at(jx + ja) != '#'){
                                                B_can = false;
                                                break;
                                            }
                                            else{
                                                made_table.at(ix + ia).at(jx + ja) = '#';
                                                rest_table.at(ix + ia).at(jx + ja) = '.';
                                            }
                                        }
                                    }
                                    if(!B_can){
                                        break;
                                    }
                                }
                            }

                            if(!B_can){
                                break;
                            }
                        }

                        if(!B_can){
                            break;
                        }
                    }

                    if(made_table != X){
                        B_can = false;
                    }
                }
                else{
                    B_can = false;
                }

                if(A_can || B_can){
                    can = true;
                    break;
                }
            }
            if(can){
                break;
            }
        }

        if(can){
            break;
        }
    }

    cout << (can ? "Yes" : "No") << '\n';
}