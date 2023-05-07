#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << X << " "
    #define debugV(X) std::cerr << #X << " = " << X << ", "
    #define debugVL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugW(Z) std::cerr << #Z << '\n'
#else
    #define debug(X)
    #define debugV(X)
    #define debugVL(Y)
    #define debugW(Z)
#endif

int main() {
    int N;
    cin >> N;
    string S = "A";
    string add;
    cin >> add;
    S += add;

    for(int i = 1; i < N; i++){
        for(int l = 1; l + i <= N; l++){
            if(S.at(l) == S.at(l+i)){
                cout << l-1 << '\n';
                break;
            }
            if(l+i == N){
                cout << l << '\n';
                break;
            }
        }
    }
}