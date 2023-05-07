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
    int N, Q;
    cin >> N >> Q;

    set<int> called;
    int last = 1;
    while(Q--){
        int type;
        cin >> type;

        if(type == 1){
            called.insert(last);
            last++;
        }
        if(type == 2){
            int x;
            cin >> x;
            called.erase(x);
        }
        if(type == 3){
            int frontNum = *begin(called);
            cout << frontNum << '\n';
        }
    }
}