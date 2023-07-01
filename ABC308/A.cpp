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
    vector<int> S(8);
    for(int i = 0; i < 8; i++){
        cin >> S.at(i);
    }

    bool OK1 = true, OK2 = true, OK3 = true;
    for(int i = 0; i < 8; i++){
        if(i+1 < 8){
            if(S.at(i) > S.at(i+1)){
                OK1 = false;
                break;
            }
        }

        if(S.at(i) < 100 || 675 < S.at(i)){
            OK2 = false;
            break;
        }

        if(S.at(i) % 25 != 0){
            OK3 = false;
            break;
        }
    }

    if(OK1 && OK2 && OK3){
        cout << "Yes" << '\n';
    }
    else{
        cout << "No" << '\n';
    }
}