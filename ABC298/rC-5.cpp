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
    int N;
    cin >> N;
    int Q;
    cin >> Q;

    map<int, multiset<int>> numInBox;
    map<int, set<int>> boxHasTheNum;
    while(Q--){
        int type;
        cin >> type;

        if(type == 1){
            int i, j;
            cin >> i >> j;

            numInBox[j].insert(i)++;
            boxHasTheNum[i].insert(j);
        }
        if(type == 2){
            int i;
            cin >> i;

            for(int num : numInBox[i]){
                cout << num << " ";
            }
            cout << '\n';
        }
        if(type == 3){
            int i;
            cin >> i;

            for(int num : boxHasTheNum[i]){
                cout << num << " ";
            }
            cout << '\n';
        }
    }

    return 0;
}