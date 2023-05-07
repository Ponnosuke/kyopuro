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
    int N, M;
    cin >> N >> M;
    string S;
    cin >> S;

    int acCnt = 0, waCnt = 0;
    bool waStart = false;
    bool OK = true;
    for(int i = 0; i < S.size(); i++){
        if(S.at(i) == 'A'){
            acCnt++;
        }
        if(S.at(i) == 'C'){
            acCnt--;
        }
        if(acCnt < 0){
            OK = false;
            break;
        }
    }

    reverse(S.begin(), S.end());
    for(int i = 0; i < S.size(); i++){
        if(S.at(i) == 'A'){
            waCnt++;
        }
        if(S.at(i) == 'W'){
            waCnt--;
        }
        if(waCnt < 0){
            OK = false;
            break;
        }
    }

    cout << (OK ? "Yes" : "No") << endl;

    return 0;
}