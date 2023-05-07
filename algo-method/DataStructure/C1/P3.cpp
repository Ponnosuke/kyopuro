#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << #X << " = " << X << ", "
    #define debugL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugP(Z) std::cerr << #Z << '\n'
#else
    #define debug(X) 3389
    #define debugL(Y) 3390
    #define debugP(Z) 3391
#endif

int main() {
    int Q;
    cin >> Q;
    vector<int> A = {3,1,4,1,5,9,2,6,5,3};

    for(int i = 0; i < Q; i++){
        int query;
        cin >> query;

        if(query == 0){
            int k;
            cin >> k;

            cout << A.at(k) << '\n';
        }
        if(query == 1){
            int k, v;
            cin >> k >> v;

            A.at(k) = v;
        }
    }
}