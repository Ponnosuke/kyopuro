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
    i64 A, B, K;
    cin >> A >> B >> K;

    // debug
    string debug_S = "";
    for(int rep = 0; rep < A; rep++){
        debug_S += 'a';
    }
    for(int rep = 0; rep < B; rep++){
        debug_S += 'b';
    }
    i64 debug_cnt = 1;
    do{
        if(debug_cnt == K){
            cerr << debug_S << '\n';
            break;
        }
        debug_cnt++;
    }while(next_permutation(debug_S.begin(), debug_S.end()));


}