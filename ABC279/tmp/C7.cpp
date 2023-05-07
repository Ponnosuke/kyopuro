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
        cin >> S[i];
    }
    for(int i = 0; i < H; i++){
        cin >> T[i];
    }

    vector<string> Svec(W), Tvec(W);
    for(int i = 0; i < W; i++){
        string tmp1 = "", tmp2 = "";
        for(int j = 0; j < H; j++){
            tmp1 += S[j][i];
            tmp2 += T[j][i];
        }
        Svec[i] = tmp1;
        Tvec[i] = tmp2;
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