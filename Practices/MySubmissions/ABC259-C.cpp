#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

vector<pair<char, int>> makeVec(string S){
    vector<pair<char, int>> ret;
    int cnt = 1;
    char prevCh = S.at(0);
    for(int i = 1; i < S.size(); i++){
        if(prevCh != S.at(i)){
            ret.push_back(make_pair(prevCh, cnt));
            prevCh = S.at(i);
            cnt = 1;
        }
        else{
            cnt++;
        }
    }
    ret.push_back(make_pair(prevCh, cnt));

    return ret;
}

int main() {
    string S, T;
    cin >> S >> T;

    vector<pair<char, int>> vecS = makeVec(S), vecT = makeVec(T);

    bool OK = true;
    if(vecS.size() != vecT.size()){
        OK = false;
    }
    else{
        for(int i = 0; i < vecS.size(); i++){
            char chS = vecS.at(i).first, chT = vecT.at(i).first;
            int cntS = vecS.at(i).second, cntT = vecT.at(i).second;

            if(chS != chT){
                OK = false;
                break;
            }

            bool impossible1 = (cntS == 1) && (cntT > 1);
            bool impossible2 = (cntS > 1) && (cntS > cntT);
            if(impossible1 || impossible2){
                OK = false;
                break;
            }
        }
    }

    cout << (OK ? "Yes" : "No") << '\n';

    return 0;
}