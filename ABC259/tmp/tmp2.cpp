#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    string S, T;
    cin >> S >> T;

    vector<pair<char, i64>> pS, pT;

    int pIndex = 0;
    for(int i = 0; i < S.size() ; i++){
        if(i == 0){
            pS.push_back(make_pair(S.at(i), 1));
            continue;
        }

        if(S.at(i) == pS.at(pIndex).first){
            pS.at(pIndex).second++;
        }
        else{
            pS.push_back(make_pair(S.at(i), 1));
            pIndex++;
        }

        // debug
        cout << "first" << i << endl;
    }

    pIndex = 0;
    for(int i = 0; i < T.size(); i++){
        if(i == 0){
            pT.push_back(make_pair(S.at(i), 1));
            continue;
        }

        if(S.at(i) == pT.at(pIndex).first){
            pT.at(pIndex).second++;
        }
        else{
            pT.push_back(make_pair(S.at(i), 1));
            pIndex++;
        }

        // debug
        cout << "second" << i << endl;
    }

    // debug
    cout << "pS.size() = " << pS.size() << endl;
    cout << "pT.size() = " << pT.size() << endl;

    if(pS.size() != pT.size()){
        cout << "No" << endl;
        return 0;
    }

    // debug
    cout << "pS.size() = " << pS.size() << endl;
    cout << "pT.size() = " << pT.size() << endl;


    for(int i = 0; i < pS.size() ; i++){
        // debug
        cout << "pS.size() = " << pS.size() << endl;
        cout << "pT.size() = " << pT.size() << endl;
        cout << "third" << i << endl;

        if(pS.at(i).first != pT.at(i).first ){
            cout << "No" << endl;
            return 0;
        }
        else{
            if((pS.at(i).second == 1) && (pT.at(i).second > 1)){
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;

}