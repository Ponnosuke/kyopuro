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
    string S;
    cin >> S;

    vector<int> idxB, idxK, idxR;
    for(int i = 0; i < S.size(); i++){
        if(S.at(i) == 'B'){
            idxB.push_back(i+1);
        }
        if(S.at(i) == 'K'){
            idxK.push_back(i+1);
        }
        if(S.at(i) == 'R'){
            idxR.push_back(i+1);
        }
    }

    bool OK1 = true, OK2 = true;
    if(idxB.at(0) % 2 == idxB.at(1) % 2){
        OK1 = false;
    }
    int x = idxR.at(0), y = idxR.at(1), z = idxK.at(0);
    if(x >= z || z >= y){
        OK2 = false;
    }

    if(OK1 && OK2){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}