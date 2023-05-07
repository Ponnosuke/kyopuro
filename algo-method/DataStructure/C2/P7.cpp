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
    stack<int> sta;
    for(int i = N-1; i >= 0; i--){
        sta.emplace(A.at(i));
    }

    int Q;
    cin >> Q;
    while(Q--){
        int type;
        cin >> type;

        if(type == 0){
            int v;
            cin >> v;

            sta.emplace(v);
        }
        if(type == 1){
            if(sta.empty()){
                cout << "Error" << '\n';
            }
            else{
                cout << sta.top() << '\n';
                sta.pop();
            }
        }
    }
}