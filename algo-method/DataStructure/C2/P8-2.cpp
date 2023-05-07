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
    for(auto &x : A)  cin >> x;
    vector<int> A_front;
    int Q;
    cin >> Q;

    while(Q--){
        int type;
        cin >> type;

        if(type == 0){
            int v;
            cin >> v;

            A_front.push_back(v);
        }
        if(type == 1){
            int v;
            cin >> v;

            A.push_back(v);
        }
        if(type == 2){
            int k;
            cin >> k;

            if(k < A_front.size()){
                int size = A_front.size();
                cout << A_front.at(size - 1 - k) << '\n';
            }
            else{
                k -= A_front.size();
                if(k < A.size()){
                    cout << A.at(k) << '\n';
                }
                else{
                    cout << "Error" << '\n';
                }
            }
        }
    }
}