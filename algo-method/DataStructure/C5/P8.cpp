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
    int Q;
    cin >> Q;

    vector<int> cnt(20001, 0);
    for(int i = -100; i <= 100; i++){
        for(int j = -100; j <= 100; j++){
            cnt.at(i*i + j*j)++;
        }
    }

    while(Q--){
        int P;
        cin >> P;

        cout << cnt.at(P) << '\n';
    }
}