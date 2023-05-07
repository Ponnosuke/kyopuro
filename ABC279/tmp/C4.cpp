/*
    AC
*/

#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    i64 H, W;
    cin >> H >> W;
    vector<string> S(H), T(H);
    for(int i = 0; i < H; i++){
        cin >> S.at(i);
    }
    for(int i = 0; i < H; i++){
        cin >> T.at(i);
    }

    vector<string> Svec(W), Tvec(W);
    for(int i = 0; i < W; i++){
        string tmp1 = "", tmp2 = "";
        for(int j = 0; j < H; j++){
            tmp1 += S.at(j).at(i);
            tmp2 += T.at(j).at(i);
        }
        Svec.at(i) = tmp1;
        Tvec.at(i) = tmp2;
    }

    sort(Svec.begin(), Svec.end());
    sort(Tvec.begin(), Tvec.end());
    
    if(Svec == Tvec){
        cout << "Yes" << '\n';
    }
    else{
        cout << "No" << '\n';
    }
}