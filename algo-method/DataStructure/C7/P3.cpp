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
    vector<int> A(N, -1);
    int head =  0, tail = 0;

    while(Q--){
        int type;
        cin >> type;

        if(type == 0){
            int v;
            cin >> v;
            A.at(tail) = v;
            tail++;
            tail %= N;
        }
        if(type == 1){
            A.at(head) = -1;
            head++;
            head %= N;
        }
    }

    for(int i = 0; i < N; i++){
        cout << A.at(i) << '\n';
    }

    return 0;
}