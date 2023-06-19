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
    i64 x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    auto get_cor = [](i64 x, i64 y) -> set<pair<i64, i64>>{
        set<pair<i64, i64>> ret;
        for(int i = -2; i <= 2; i++){
            for(int j = -2; j <= 2; j++){
                if(i*i + j*j == 5){
                    ret.emplace(x + i, y + j);
                }
            }
        }

        return ret;
    };

    set<pair<i64, i64>> st1 = get_cor(x1, y1), st2 = get_cor(x2, y2);
    bool OK = false;

    // debug
    debugWL(st1);
    for(auto [p, q] : st1){
        debugV(p);
        debugVL(q);
    }
    debugWL(st2);
    for(auto [p, q] : st2){
        debugV(p);
        debugVL(q);
    }

    for(auto ele : st1){
        if(st2.count(ele)){
            OK = true;
            break;
        }
    }

    cout << (OK ? "Yes" : "No") << endl;
}