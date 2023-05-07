#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N;
    cin >> N;
    vector<string> S(N);
    set<string> Sset;
    for(int i = 0; i < N; i++){
        cin >> S.at(i);
        if(Sset.count(S.at(i))){
            cout << "No" << endl;
            return 0;
        }
        else{
            Sset.insert(S.at(i));
        }
    }

    string cond1 = "HDCS", cond2 = "A23456789TJQK";
    bool OK = true;
    for(int i = 0; i < N; i++){
        bool tmpOK1 = false, tmpOK2 = false;
        for(char ch : cond1){
            if(S.at(i).at(0) == ch){
                tmpOK1 = true;
            }
        }
        for(char ch : cond2){
            if(S.at(i).at(1) == ch){
                tmpOK2 = true;
            }
        }

        if(!tmpOK1 || !tmpOK2){
            OK = false;
            break;
        }
    }

    cout << (OK ? "Yes" : "No") << '\n';


}