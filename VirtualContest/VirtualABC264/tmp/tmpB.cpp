#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int R, C;
    cin >> R >> C;
    R--;
    C--;

    vector<vector<string>> masu(15, vector<string>(15));

    string B = "black", W = "white";
    int bR = 0, bC = 0, eR = 14, eC = 14;
    for(int i = 0; i < 7; i++){
        string now;
        if(i % 2 == 0){
            now = B;
        }
        else{
            now = W;
        }

        for(int j = bR; j <= eR; j++){
            masu.at(bR).at(j) = now;
            masu.at(eR).at(j) = now;
            masu.at(j).at(bC) = now;
            masu.at(j).at(eC) = now;
        }

        bR++;
        bC++;
        eR--;
        eC--;
    }
    masu.at(7).at(7) = W;

    // debug
    /*
    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 15; j++){
            string now = masu.at(i).at(j);
            if(now == "black")  cout << "b";
            else cout << "w";

            if(j < 14) cout << " ";
        }
        cout << endl;
    }
    */

   cout << masu.at(R).at(C) << endl;
}