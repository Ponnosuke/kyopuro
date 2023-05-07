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
    vector<char> S(3), T(3);
    for(int i = 0; i < 3; i++){
        cin >> S.at(i);
    }
    for(int i = 0; i < 3; i++){
        cin >> T.at(i);
    }

    int cntS = 0, cntT = 0;
    for(int i = 0; i < 3; i++){
        for(int j = i+1; j < 3; j++){
            if(S.at(i) > S.at(j)){
                cntS++;
            }
            if(T.at(i) > T.at(j)){
                cntT++;
            }
        }
    }

    if((cntS % 2) == (cntT % 2)){
        cout << "Yes" << '\n';
    }
    else{
        cout << "No" << '\n';
    }
}