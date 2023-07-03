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
    for(int i = 0; i < HA; i++){
        cin >> A.at(i);
    }
    int HB, WB;
    cin >> HB >> WB;
    vector<string> B(HB);
    for(int i = 0; i < HB; i++){
        cin >> B.at(i);
    }
    int HX, WX;
    cin >> HX >> WX;
    vector<string> X(HX);
    for(int i = 0; i < HX; i++){
        cin >> X.at(i);
    }


    bool can = false;
    // 絶対座標
    // 左上の位置
    for(int ia = 1 - HA; ia < HX; ia++){
        for(int ja = 1 - WA; ja < WX; ja++){
            for(int ib = 1 - HB; ib < HX; ib++){
                for(int jb = 1 - WB; jb < WX; jb++){

                    vector<string> sheet(HX, string(WX, '.'));

                    // Aの相対座標
                    // Aの左上からの位置
                    bool OK = true;
                    for(int h = 0; h < HA; h++){
                        for(int w = 0; w < WA; w++){
                            if(A.at(h).at(w) == '#'){
                                int abs_h = ia + h, abs_w = ja + w;
                                if(abs_h < 0 || HX <= abs_h || abs_w < 0 || WX <= abs_w){
                                    OK = false;
                                    break;
                                }

                                sheet.at(abs_h).at(abs_w) = '#';
                            }
                        }
                        if(!OK){
                            break;
                        }
                    }
                    if(!OK){
                        continue;
                    }

                    // Bの相対座標
                    // Bの左上からの位置
                    for(int h = 0; h < HB; h++){
                        for(int w = 0; w < WB; w++){
                            if(B.at(h).at(w) == '#'){
                                int abs_h = ib + h, abs_w = jb + w;
                                if(abs_h < 0 || HX <= abs_h || abs_w < 0 || WX <= abs_w){
                                    OK = false;
                                    break;
                                }

                                sheet.at(abs_h).at(abs_w) = '#';
                            }
                        }
                        if(!OK){
                            break;
                        }
                    }
                    
                    if(OK){
                        if(X == sheet){
                            can = true;
                        }
                    }
                }
            }
        }
    }

    cout << (can ? "Yes" : "No") << endl;

    return 0;
}