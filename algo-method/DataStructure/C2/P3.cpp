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
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }
    int Q;
    cin >> Q;

    for(int i = 0; i < Q; i++){
        int type;
        cin >> type;

        if(type == 0){
            int v;
            cin >> v;
            A.emplace_back(v);
        }
        if(type == 1){
            int vecSize = A.size();
            if(vecSize > 0){
                cout << A.at(vecSize - 1) << endl;
                A.pop_back();
            }
            else{
                cout << "Error" << endl;
            }
        }
    }
}