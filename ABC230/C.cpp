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
    i64 N, A, B;
    cin >> N >> A >> B;
    i64 P, Q, R, S;
    cin >> P >> Q >> R >> S;

    for(i64 i = P; i <= Q; i++){
        for(i64 j = R; j <= S; j++){
            i64 diff_i = abs(A - i), diff_j = abs(B - j);
            if(diff_i == diff_j){
                cout << '#';
            }
            else{
                cout << '.';
            }
        }
        cout << '\n';
    }
}