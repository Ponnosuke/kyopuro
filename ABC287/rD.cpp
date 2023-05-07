#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << X << " "
    #define debugV(X) std::cerr << #X << " = " << X << ", "
    #define debugVL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugWL(Z) std::cerr << #Z << '\n'
#else
    #define debug(X)
    #define debugV(X)
    #define debugVL(Y)
    #define debugWL(Z)
#endif

int main() {
    string S, T;
    cin >> S >> T;

    int Tsize = T.size(), Ssize = S.size();

    vector<bool> frontMatch(Tsize + 1, false);
    frontMatch.at(0) = true;
    for(int i = 0; i < Tsize; i++){
        if(S.at(i) == '?' || T.at(i) == '?' || S.at(i) == T.at(i)){
            frontMatch.at(i+1) = true;
        }
        else{
            break;
        }
    }

    

    reverse(S.begin(), S.end());
    reverse(T.begin(), T.end());
    vector<bool> backMatch(Tsize + 1, false);
    backMatch.at(0) = true;
    for(int i = 0; i < Tsize; i++){
        if(S.at(i) == '?' || T.at(i) == '?' || S.at(i) == T.at(i)){
            backMatch.at(i+1) = true;
        }
        else{
            break;
        }
    }

    for(int x = 0; x <= Tsize; x++){
        debugV(x);
        if(frontMatch.at(x)){
            debugWL(true);
        }
        else{
            debugWL(false);
        }
    }
    for(int x = 0; x <= Tsize; x++){
        debugV(x);
        if(backMatch.at(x)){
            debugWL(true);
        }
        else{
            debugWL(false);
        }
    }
    debugWL();

    for(int x = 0; x <= Tsize; x++){
        if(frontMatch.at(x) && backMatch.at(Tsize - x)){
            cout << "Yes" << '\n';
        }
        else{
            cout << "No" << '\n';
        }
    }
}