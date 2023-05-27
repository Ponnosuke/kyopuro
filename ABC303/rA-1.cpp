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
    cin >> S >> T;

    bool OK = true;
    for(int i = 0; i < N; i++){
        char chS = S.at(i), chT = T.at(i);

        if(chS == 'l'){
            chS = '1';
        }
        if(chS == 'o'){
            chS = '0';
        }
        if(chT == 'l'){
            chT = '1';
        }
        if(chT == 'o'){
            chT = '0';
        }

        if(chS != chT){
            OK = false;
            break;
        }
    }

    cout << (OK ? "Yes" : "No") << endl;

    return 0;
}