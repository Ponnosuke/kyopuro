#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    string S;
    cin >> S;

    vector<bool> isAllLying(7, false);  // その列のピンが全部倒れているか否か

    if(S.at(6) == '0')  isAllLying.at(0) = true;
    if(S.at(3) == '0')  isAllLying.at(1) = true;
    if(S.at(1) == '0'  &&  S.at(7) == '0')  isAllLying.at(2) = true;
    if(S.at(0) == '0'  &&  S.at(4) == '0')  isAllLying.at(3) = true;
    if(S.at(2) == '0'  &&  S.at(8) == '0')  isAllLying.at(4) = true;
    if(S.at(5) == '0')  isAllLying.at(5) = true;
    if(S.at(9) == '0')  isAllLying.at(6) = true;

    bool OK1 = false, OK2 = false, OK3 = false, OK4 = false;
    for(auto boo : isAllLying){
        if(!boo)  OK1 = true;
        if(boo && OK1)  OK2 = true;
        if((!boo) &&  OK2)  OK3 = true;
    }

    if(S.at(0) == '0')  OK4 = true;

    if(OK1 && OK2 && OK3 && OK4){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}