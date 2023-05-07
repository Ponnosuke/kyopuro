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
    int N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;

    if(N >= 3){
        if(A > 0 && D > 0){
            if(B == 0 && C == 0){
                cout << "No" << endl;
                return 0;
            }
            else{
                if(abs(B-C) > 1){
                    cout << "No" << endl;
                    return 0;
                }
                else{
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    
    if(abs(B - C) > 1){
        cout << "No" << endl;
    }
    else{
        cout << "Yes" << endl;
    }
}