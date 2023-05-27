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
    string S, T;
    cin >> S;
    cin >> T;

    bool OK = true;
    for(int i = 0; i < N; i++){
        if(S.at(i) == T.at(i)){
            // do nothing
        }
        else if(S.at(i) == '1' && T.at(i) == 'l'){
            // do nothing
        }
        else if(S.at(i) == 'l' && T.at(i) == '1'){
            // do nothing
        }
        else if(S.at(i) == '0' && T.at(i) == 'o'){
            // do nothing
        }
        else if(S.at(i) == 'o' && T.at(i) == '0'){
            // do nothing
        }
        else{
            OK = false;
            break;
        }
    }

    cout << (OK ? "Yes" : "No") << endl;

    return 0;
}