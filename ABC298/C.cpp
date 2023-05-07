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
    i64 N;
    cin >> N;
    i64 Q;
    cin >> Q;

    map<i64, map<i64, i64>> numInBox;
    map<i64, set<i64>> boxHasTheNum;
    while(Q--){
        int type;
        cin >> type;

        if(type == 1){
            int i, j;
            cin >> i >> j;

            numInBox[j][i]++;
            boxHasTheNum[i].insert(j);
        }
        if(type == 2){
            int i;
            cin >> i;

            for(auto [num, cnt] : numInBox[i]){
                for(int j = 0; j < cnt; j++){  // ここのカウンタ変数に i を使っていたので間違えないように注意
                    cout << num << " ";
                }
            }
            cout << '\n';
        }
        if(type == 3){
            int i;
            cin >> i;

            for(auto num : boxHasTheNum[i]){
                cout << num << " ";
            }
            cout << '\n';
        }
    }

    return 0;
}