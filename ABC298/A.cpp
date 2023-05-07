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
    int N;
    cin >> N;
    string S;
    cin >> S;

    bool OK = false, NG = false;
    for(int i = 0; i < N; i++){
        if(S.at(i) == 'o'){
            OK = true;
        }
        else if(S.at(i) == 'x'){
            NG = true;
            break;
        }
    }

    if(OK && !NG){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}