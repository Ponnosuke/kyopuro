#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    string S;
    cin >> S;

    // 同じ文字の判定
    bool OK1 = true;
    set<char> chSet;
    for(int i = 0; i < S.size(); i++){
        if(chSet.count(S.at(i))){
            OK1 = false;
            break;
        }
        else{
            chSet.insert(S.at(i));
        }
    }
    if(!OK1){
        cout << "No" << endl;
        return 0;
    }

    // 大文字小文字の判定
    int Lcnt = 0, Ucnt = 0, Scnt = 0; 
    for(int i = 0; i < S.size(); i++){
        Scnt += S.at(i);
        Ucnt += toupper(S.at(i));
        Lcnt += tolower(S.at(i));
    }

    bool OK2 = true;
    if((Scnt == Ucnt) || (Scnt == Lcnt)){
        OK2 = false;
    }
    
    if(OK2){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }

}