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
    for(int &x : A)  cin >> x;
    int Q;
    cin >> Q;

    while(Q--){
        int type;
        cin >> type;
        if(type == 0){
            reverse(A.begin(), A.end());
        }
        if(type == 1){
            int v;
            cin >> v;
            A.emplace_back(v);
        }
        if(type == 2){
            if(A.empty()){
                cout << "Error" << '\n';
            }
            else{
                cout << A.back() << '\n';
                A.pop_back();
            }
        }
    }
}