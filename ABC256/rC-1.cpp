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
    vector<int> h(3, 0), w(3, 0);
    for(int i = 0; i < 3; i++){
        cin >> h.at(i);
    }
    for(int i = 0; i < 3; i++){
        cin >> w.at(i);
    }

    vector<vector<int>> field(3, vector<int>(3, 0));
    i64 cnt = 0;
    for(int ul = 1; ul <= 28; ul++){
        for(int ur = 1; ur + ul <= 29; ur++){
            for(int dl = 1; dl + ul <= 29; dl++){
                for(int dr = 1; dr + dl <= 29; dr++){
                    field.at(0).at(2) = h.at(0) - ul - ur;
                    field.at(1).at(2) = h.at(1) - dl - dr;
                    field.at(2).at(0) = w.at(0) - ul - dl;
                    field.at(2).at(1) = w.at(1) - ur - dr;

                    if(field.at(0).at(2) < 1){
                        continue;
                    }
                    if(field.at(1).at(2) < 1){
                        continue;
                    }
                    if(field.at(2).at(0) < 1){
                        continue;
                    }
                    if(field.at(2).at(1) < 1){
                        continue;
                    }

                    int check1 = field.at(0).at(2) + field.at(1).at(2);
                    int check2 = field.at(2).at(0) + field.at(2).at(1);

                    // debug
                    debugWL(field);
                    field.at(0).at(0) = ul;
                    field.at(0).at(1) = ur;
                    field.at(1).at(0) = dl;
                    field.at(1).at(1) = dr;
                    for(int i = 0; i < 3; i++){
                        for(int j = 0; j < 3; j++){
                            debug(field.at(i).at(j));
                        }
                        debugWL();
                    }

                    if(check1 >= w.at(2) || check2 >= h.at(2)){
                        continue;
                    }

                    if((w.at(2) - check1) == (h.at(2) - check2)){
                        cnt++;
                    }
                }
            }
        }
    }

    cout << cnt << '\n';
}