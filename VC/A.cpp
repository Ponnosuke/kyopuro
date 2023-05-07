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
    vector<string> S(10);
    for(int i = 0; i < 10; i++){
        cin >> S.at(i);
    }
    int A = 11, B = -1, C = 11, D = -1;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            char now = S.at(i).at(j);
            if(now == '#'){
                A = min(A, i);
                B = max(B, i);
                C = min(C, j);
                D = max(D, j);
            }
        }
    }
    A++;
    B++;
    C++;
    D++;
    cout << A << " " << B << '\n';
    cout << C << " " << D << '\n';
}