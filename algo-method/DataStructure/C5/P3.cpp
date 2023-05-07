#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << X << " "
    #define debugV(X) std::cerr << #X << " = " << X << ", "
    #define debugVL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugWL(Z) std::cerr << #Z << '\n'
#else
    #define debug(X)
    #define debugV(X)
    #define debugVL(Y)
    #define debugWL(Z)
#endif

int main() {
    int N;
    cin >> N;
    vector<int> cnt(100001, 0);
    for(int i = 0; i < N; i++){
        int A;
        cin >> A;
        cnt.at(A)++;
    }

    int Q;
    cin >> Q;
    while(Q--){
        int type;
        cin >> type;

        if(type == 0){
            int v;
            cin >> v;
            cnt.at(v)++;
        }
        if(type == 1){
            int v;
            cin >> v;
            cnt.at(v) = 0;
        }
        if(type == 2){
            int v;
            cin >> v;
            cout << cnt.at(v) << '\n';
        }
    }
}